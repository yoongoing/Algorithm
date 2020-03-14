#include <stdio.h>
#include <string.h>
int main(){
	int t,i,j,k;
	scanf("%d",&t);
	for(i=0;i<t;i++){
		char data[1000];
		int n;
		scanf("%d %s",&n,data);
		for(j=0;j<strlen(data);j++){
			if(n == j+1){
				for(k=j;k<strlen(data);k++){
					data[k] = data[k+1];
					// printf("%s\n",data); 
				}
				
			}
		}
		printf("%s\n",data);
	}

}