#include <stdio.h>

int main(){
	int N,K,j,i;
	int S[10001] = {0}; 
	scanf("%d %d",&N,&K);
	for(int i=1; i<=N; i++){
		if(N % i == 0){
			S[i-1] = N/i;
			
		}
	}
	for(j=0,i=N-1; i>=0; i--){
		if(S[i] != 0){
			if(j == K-1){
				printf("%d\n",S[i]);
				return 0;
			}
			j++;
		}	
	}
	printf("0\n");
}