#include <stdio.h>

int main(){
	int i;
	for(i=0; i<3; i++){
		int j,n;
		int total = 0;
		for(j=0; j<4; j++){
			scanf("%d",&n);
			if(n == 1){
				total++;
			}
		}
		if(total == 1){
			printf("C\n");
		}
		else if(total == 2){
			printf("B\n");
		}
		else if(total == 3){
			printf("A\n");
		}
		else if(total == 0){
			printf("D\n");
		}
		else if(total == 4){
			printf("E\n");
		}
	}
	
}
/*
#include<stdio.h>

int main(){
	int i, sum = 0, j;
	char data[6] = {'D','C','B','A','E'};
	for (i = 0; i<3; i++){
		for (j = 0; j < 4; j++){
			int x;
			scanf("%d", &x);
			sum += x;
		}
		printf("%c\n", data[sum]);
		sum = 0;
	}
	return 0;
}
*/