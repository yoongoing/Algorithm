#include <stdio.h>
#include <string.h>

int main(){
	int n,i,j,m,a,flag;
	char data1[1000] = {0};
	char data2[1000] = {0};
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%s",data1);
		// for(j=0;j<strlen(data1);j++){
		// 	data2[j] = data1[j];
		// }
		if(i==0){
			for(j=0;j<strlen(data1);j++){
				data2[j] = data1[j];
				a = strlen(data1);
			}
		}
		else if(strcmp(data1,data2)>0){				
			for(j=0;j<strlen(data1);j++){
				data2[j] = data2[j];
			}
		}
		else if(strcmp(data1,data2)==0){
			for(j = 0; j<strlen(data1);j++)
			{
				data2[j] = data1[j]; 
			}
		}
		else if(strcmp(data1,data2)<0){
			a = strlen(data1);
			if(strlen(data1)<strlen(data2)){
				for(j=0;j<strlen(data2);j++){
					data2[j] = data1[j];
				}
			}			
			for(j=0;j<strlen(data1);j++){				
				data2[j] = data1[j];
			}
		}

	}
	for(i=0;i<a;i++){
		printf("%c",data2[i]);
	}
	printf("\n");	
	
}	