#include <stdio.h>

int main(){
	int t,i,j;
	char data[15] = {0};
	scanf("%d",&t);
	
	for(i=0; i<t; i++){
		int sum = 0;
		int check[10] = {0};
		scanf("%s",data);
		for(j=0; data[j]; j++){
			check[data[j] - '0'] = 1;
		}
		for(j=0; j<10; j++){
			if(check[j]){
				sum++;
			}
		}
		printf("%d\n",sum);
	}	
}


