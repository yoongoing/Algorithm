#include <stdio.h>
#include <string.h>
int main(){
	int t,i,j,k,l,z;
	scanf("%d",&t);
	for(i=0;i<t;i++){
		char data1[1000]={0};
		int data2[1000]={0};
		int n;
		scanf("%d",&n);
		for(j=0;j<n;j++){
			scanf("%d",&data2[j]);	
		}

		scanf("%s",data1);
		int zz =0;
		for(k=0;k<n;k++){
			for(l=0;l<strlen(data1);l++){							
				if(data2[k]-zz== l+1){
					//printf("%d\n", data2[l]-zz);
					zz ++ ;					
					int aa = l;
					for(z=0;z<strlen(data1);z++){
						data1[aa] = data1[aa+1];
						aa++;	

					}
					
					//printf("%s\n",data1);

				}
						
			}
			
		}
		printf("%s\n", data1);

	}

		// scanf("%d %s",&n,data);
		// for(j=0;j<strlen(data);j++){
		// 	if(n == j+1){
		// 		for(k=j;k<strlen(data);k++){
		// 			data[k] = data[k+1];
		// 			// printf("%s\n",data); 
		// 		}
				
		// 	}
		// }
		// printf("%s\n",data);
}

