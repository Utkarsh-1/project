#include <stdio.h>
#include <stdlib.h>

int conv(FILE *f, FILE *fw)
{
  int p=0,temp;
  while()
    {
    	fscanf(f, "%d", &temp);
		p++;
	}
	int v[p];
	for(int i=0;i<p;++i)
		fscanf(f, "%d", &v[i]); 
    for(int i=0; i<p; ++i)
    {
      int current=v[i];
      switch(current)
       {
       	 case 0 :{ switch(p)
       	           {
       	           	 case 0: printf("2 \n"); 
			         break;
		         case 1: printf("3 \n");
			         break;
		         case 2: printf("4 \n");
			         break;
                         case 3: printf("5 \n");
			         break;
			 case 4: printf("6 \n");
			         break;
			 case 5: printf("7 \n");
			         break;
	                 case 6: printf("0 \n");
			         break;		
		         case 7: printf("1 \n");
			         break;
		   }
				
	         } break;
       	 
		 case 1 :{ switch(p)
       	           {
       	           	 case 0: printf("1 \n");
			          break;
		         case 1: printf("2 \n");
		                 break;
			 case 2: printf("3 \n");
		                 break;
                         case 3: printf("4 \n");
		                 break;
			 case 4: printf("5 \n"); 
		                 break;
			 case 5: printf("6 \n");
				 break;
	                 case 6: printf("7 \n");
				 break;		
		          case 7: printf("0 \n");
				 break;
					}
				
			     } break;
       	
       	 case 2 :{ switch(p)
       	           {
       	           	 case 0: printf("0 \n");
			         break;
		         case 1: printf("1 \n"); 
			         break;
			 case 2: printf("2 \n");
			         break;
                         case 3: printf("3 \n");  
			         break;
			 case 4: printf("4 \n"); 
			         break;
			 case 5: printf("5 \n");  
			         break;
	                 case 6: printf("6 \n"); 
			         break;		
		         case 7: printf("7 \n");
			         break;
		     }
				
	           } break;
       	
       	 case 3 :{ switch(p)
       	           {
       	           	 case 0: printf("7 \n");
			         break;
			 case 1: printf("0 \n"); 
			         break;
			 case 2: printf("1 \n"); 
			         break;
                         case 3: printf("2 \n");
			         break;
			 case 4: printf("3 \n");
			         break;
			 case 5: printf("4 \n");
			         break;
	                 case 6: printf("5 \n");
			         break;		
		         case 7: printf("6 \n"); 
			         break;
					}
				
			     } break;
       	 case 4 :{ switch(p)
       	           {
       	           	 case 0: printf("6 \n");
			         break;
			 case 1: printf("7 \n");
			         break;
		         case 2: printf("0 \n");
			         break;
                         case 3: printf("1 \n");
			         break;
			 case 4: printf("2 \n");
			         break;
			 case 5: printf("3 \n");
			         break;
	                 case 6: printf("4 \n"); 
			         break;		
		         case 7: printf("5 \n"); 
			         break;
		    }
				
	         } break;
       	
       	 case 5 :{ switch(p)
       	           {
       	           	 case 0: printf("5 \n");
			         break;
			 case 1: printf("6 \n"); 
			         break;
			 case 2: printf("7 \n"); 
			         break;
                         case 3: printf("0 \n");
			         break;
			 case 4: printf("1 \n");
			         break;
			 case 5: printf("2 \n");
			         break;
	                 case 6: printf("3 \n"); 
			         break;		
		         case 7: printf("4 \n"); 
			         break;
		    }
				
	           } break;
       	
       	 case 6 :{ switch(p)
       	           {
       	           	 case 0: printf("4 \n");
			         break;
			 case 1: printf("5 \n"); 
			         break;
			 case 2: printf("6 \n");
			         break;
                         case 3: printf("7 \n");
			         break;
			 case 4: printf("0 \n"); 
			         break;
			 case 5: printf("1 \n");
			         break;
	                 case 6: printf("2 \n"); 
			         break;		
		         case 7: printf("3 \n");
			         break;
		     }
				
	           } break;
       	
       	 case 7 :{ switch(p)
       	           {
       	           	 case 0: printf("3 \n");
			         break;
		         case 1: printf("4 \n");
			         break;
			 case 2: printf("5 \n");
			         break;
                         case 3: printf("6 \n"); 
			         break;
			 case 4: printf("7 \n");
			         break;
			 case 5: printf("0 \n");
			         break;
	                 case 6: printf("1 \n");
			         break;		
		         case 7: printf("2 \n");
			         break;
		    }
				
	          } break;
       	
	   }
	   
	p=current;
		
    }
  return 0;  
}
