bool check(FILE *a, FILE *b){
  FILE *ca=a, *cb=b; int size1,size2,temp,ct=0;
  while(fscanf(ca," %d",&temp)) ct++; size1=ct; ct=0;
  while(fscanf(cb," %d",&temp)) ct++; size2=ct;
  int f1[size1], f2[size2];
  for(int i=0;i<size1;++i) fscanf(a," %d",&f1[i]);
  for(int i=0;i<size2;++i) fscanf(a," %d",&f2[i]);
  bool same=false;
  for(int i=0;i<size1;++i){
    if(f1[i]==f2[0]){
      for(int j=0;j<size2;++i){
        if(f2[j]!=f1[(j+i)%size1]) break;
      }
      return true;
    }
  }
  return false;
}
