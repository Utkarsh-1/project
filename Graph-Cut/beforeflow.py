#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Jan 21 21:48:50 2018

@author: madhur
"""


from scipy.misc import imread, imshow
from sklearn.mixture import GaussianMixture as GMM


def iread():
    X=imread('2.jpg')
    global old
    old=X.shape
    print(old)
    X=X.reshape(-1,3)
    gmm=GMM(covariance_type='full', n_components=2)
    gmm.fit(X)
    clusters=gmm.predict_proba(X)
    clusters=clusters.reshape(old[0],old[1],2)
    f=open("prob.txt","w")
    for i in range(old[0]):
        for j in range(old[1]):
            f.write(str(clusters[i][j][0])+" "+str(clusters[i][j][1])+"\n")
    f.close()
    gmm.fit(X)
    label=gmm.predict(X)
    label=label.reshape(old[0],old[1])
    imshow(label)
    return clusters

def cur(i,j):
    return i*old[0]+j+2

def norm(l1,l2):
    ans=0
    for i in range(len(l1)):
        ans+=(l1[i]-l2[i])**2
    return ans


def gcut(clusters):
    import graph_tool.flow
    import graph_tool.all as gt
    import numpy as np
    f=open("weights.txt",'w')
    g=gt.Graph(directed=False)
    wt=g.new_edge_property("long double")
    g.add_vertex(old[0]*old[1]+2)
    s=g.vertex(0)
    t=g.vertex(1)
    beta=1
    for i in range(old[0]):
        for j in range(old[1]):
            e=g.add_edge(s,g.vertex(cur(i,j)))
            wt[e]=-np.log(clusters[i][j][0])
            f.write(str(wt[e])+" ")
            e=g.add_edge(t,g.vertex(cur(i,j)))
            wt[e]=-np.log(clusters[i][j][1])
            f.write(str(wt[e])+" ")
            if i>0:
                e=g.add_edge(g.vertex(cur(i-1,j)),g.vertex(cur(i,j)))
                wt[e]=np.exp(-beta*norm(clusters[i][j], clusters[i-1][j]))
                f.write(str(wt[e])+" ")
            if i>0 and j!=old[1]-1:
                e=g.add_edge(g.vertex(cur(i,j)),g.vertex(cur(i-1,j+1)))
                wt[e]=np.exp(-beta*norm(clusters[i][j],clusters[i-1][j+1]))/1.4142135
                f.write(str(wt[e])+" ")
            if j!=old[1]-1:
                e=g.add_edge(g.vertex(cur(i,j)),g.vertex(cur(i,j+1)))
                wt[e]=np.exp(-beta*norm(clusters[i][j],clusters[i][j+1]))
                f.write(str(wt[e])+" ")
            if i!=old[0]-1 and j!=old[1]-1:
                e=g.add_edge(g.vertex(cur(i+1,j+1)),g.vertex(cur(i,j)))
                wt[e]=np.exp(-beta*norm(clusters[i][j],clusters[i+1][j+1]))/1.4142135
                f.write(str(wt[e])+" ")
            if i!=old[0]-1:
                e=g.add_edge(g.vertex(cur(i+1,j)),g.vertex(cur(i,j)))
                wt[e]=np.exp(-beta*norm(clusters[i][j],clusters[i+1][j]))
                f.write(str(wt[e])+" ")
            if i!=old[0]-1 and j!=0:
                e=g.add_edge(g.vertex(cur(i,j)),g.vertex(cur(i+1,j-1)))
                wt[e]=np.exp(-beta*norm(clusters[i][j],clusters[i+1][j-1]))/1.4142135
                f.write(str(wt[e])+" ")
            if j!=0:
                e=g.add_edge(g.vertex(cur(i,j)),g.vertex(cur(i,j-1)))
                wt[e]=np.exp(-beta*norm(clusters[i][j],clusters[i][j-1]))
                f.write(str(wt[e]))
            if j!=0 and i!=0:
                e=g.add_edge(g.vertex(cur(i-1,j-1)),g.vertex(cur(i,j)))
                wt[e]=np.exp(-beta*norm(clusters[i][j],clusters[i-1][j-1]))/1.4142135
                f.write(str(wt[e])+" ")
            f.write("\n")
    f.close()
    res=g.new_edge_property("long double")
    wt=res
    print(g.num_vertices(), g.num_edges())
    print("Graph created\nRunning cuts, yeah")
    cst,part=graph_tool.flow.min_st_cut(g,s,wt,res)
    print("Graph cut done. Cost :{}".format(cst))
    ans=np.ndarray((old[0],old[1]), dtype=bool)
    for i in range(old[0]):
        for j in range(old[1]):
            ans[i][j]=part[g.vertex(cur(i,j))]
    imshow(ans)
    return

    
if __name__=="__main__":
    op=iread()
    gcut(op)
