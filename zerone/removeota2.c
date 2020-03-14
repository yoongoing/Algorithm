#include <stdio.h>
#include <string.h>
int main(){
	int t,i,j,k,l;
	scanf("%d",&t);
	for(i=0;i<t;i++){
		char data1[1000]={0};
		int data2[1000]={0};
		int n,j;
		scanf("%d",&n);
		for(j=0;j<n;j++){
			scanf("%d",&data2[j]);	
		}

		scanf("%s",data1);
		//int zz =0;
		
		for(k=0;k<strlen(data1);k++){
			int flag = 0;
			for(l=0;l<n;l++){							
				if(data2[l] == k+1){
					flag = 1;										
					//printf("%c",data1[k]);
								
				}
						
			}
			if(flag == 0){
				printf("%c",data1[k]);
			}
			
			
		}
		printf("\n");
		//printf("%c\n", data1[l]);
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

