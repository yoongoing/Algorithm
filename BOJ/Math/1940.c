#include <stdio.h>

int main(){
	int t,n,i,j,sum = 0;
	int data[15001] = {0};
	scanf("%d %d",&t,&n);
	for(i=0; i<t; i++){
		scanf("%d",&data[i]);
	}
	for(i=0; i<t; i++){
		for(j=i+1; j<t; j++){
			if(data[i] + data[j] == n){
				sum++;
			} 
		}
	}
	printf("%d\n",sum );
}