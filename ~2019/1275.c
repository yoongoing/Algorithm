#include <stdio.h>

int main(){
	int i,j,n,turn;
	long long data[100000] = {0};
	long long n1,n2,c1,c2;
	scanf("%d %d",&n,&turn);
	for(i=0; i<n; i++){
		scanf("%lld",&data[i]);
	}
	for(i=0; i<turn; i++){
		long long sum = 0;
		scanf("%lld %lld %lld %lld",&n1,&n2,&c1,&c2);
		if(n1 > n2){
			for(j=n1-1; j>=n2-1; j--){
				sum += data[j];
			}
		}
		else{
			for(j=n1-1; j<=n2-1; j++){
				sum += data[j];
			}
		}	
		printf("%lld\n",sum);
		data[c1-1] = c2;
	}

}