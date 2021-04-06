#include <stdio.h>

int main(){
	int sum1,sum2,i;
	int total = 0;
	int total_1 = 0;
	for(i=0; i<4; i++){
		scanf("%d %d",&sum1,&sum2);
		total = total - sum1 + sum2;
		if(total > total_1){
			total_1 = total;
		}
	}
	printf("%d\n",total_1);
}