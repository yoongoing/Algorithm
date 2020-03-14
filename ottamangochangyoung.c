#include <stdio.h>
#include <string.h>

int main(){
	int n,m,i,j;
	char data[100] = {0};
	scanf("%d",&n);
	for(i=0; i<n; i++){
		scanf("%d %s",&m,data);
		for(j=0; j<strlen(data); j++){
			if(m != j+1){
				printf("%c",data[j]);
			}
		}
		printf("\n");
	}
}
/*
data_len = strlen(data);
		for (j = 0; j < data_len; j++){
			if (j == hole-1) continue;
			else printf("%c",data[j]);
		}
*/		