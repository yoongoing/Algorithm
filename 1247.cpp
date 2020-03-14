#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){
	for(int i=0; i<3; i++){
		long long int data[1000000] = {0};
		int a;
		scanf("%d",&a); 
		long long int sum = 0;
		int flag = 0;
		for(int j=0; j<a; j++){
			scanf("%lld",&data[j]);
		}
		sort(data,data+a);
		if(data[0] > 0){
			printf("+\n");
			continue;
		}			
		else if(data[a-1] < 0){
			printf("-\n");
			continue;
		}
		else{
			for(int j=0; j<a/2; j++){
				if(data[j]>=0 && sum>0){
					printf("+\n");
					flag = 1;
					break;
				}
				else if(sum<0 && data[a-j-1]<=0) {
					printf("-\n");
					flag = 1;
					break;
				}
				sum += (data[j]+data[a-j-1]);
				//printf("%lld\n",sum );
			}
			if(flag == 1){
				break;
			}
			if(a%2 != 0){
				sum += data[(a/2)];
			}
			//printf("%lld\n",sum );
			if(sum == 0){
				printf("0\n");
			}
			else if(sum > 0){
				printf("+\n");
			}
			else{
				printf("-\n");
			}

		}
	}	
}