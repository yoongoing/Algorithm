#include <stdio.h>

int main(){
	int i,n;
	char data[100];
	scanf("%d"&n);
	for(i=0; i<n; i++){
		scanf("%s",data);
		printf("%s\n",data);
	}
}