#include <stdio.h>
#include <string.h>

int main(){
	int i,j,k,t;	
	scanf("%d",&t);
	for(i=0; i<t; i++){
		int scan,a;
		char data[1000] = {0};
		scanf("%d %s",&scan,data);
		a = strlen(data); 
		for(j=0; j<a; j++){
			for(k=0; k<scan; k++){
				printf("%c",data[j]);
			}
		}
		printf("\n");
	}
}