#include <stdio.h>

int main(){
	int i;
	int check[31] = {0};
	int data[30] = {0};
	for(i=1; i<=28; i++){
		scanf("%d",&data[i]);
		check[data[i]] = 1;
	}
	for(i=1; i<=30; i++){
		if(check[i] == 0){
			printf("%d",i);
			printf("\n");
		}
	}
}