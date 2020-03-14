#include <stdio.h>
int main(){
    int t,i,j,k;
    int h,w,n;
    scanf("%d",&t);
    for(i=0;i<t;i++){        
        scanf("%d %d %d",&h,&w,&n);
        for(j=1;j<=h;j++){
            for(k=1;k<=w;k++){
                if(n%h == 0){
                    if(n/h==j){
                        printf("%d\n",(j*100)+h );
                        break;
                        
                    }
                    else if(n/h == w){
                        printf("%d\n",(h*100)+w);
                        break;
                    }
                }
                else if(n%h == j){
                    if(n/h==k-1){
                        printf("%d\n",(j*100)+k );
                    }
                    
                    // break;
                }
                //else if()
                
            }
        }
            
 
    }
}