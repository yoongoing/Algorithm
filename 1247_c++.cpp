#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){
	for(int i=0; i<3; i++){
		long long int data[1000000] = {0};
		int a;
		scanf("%d",&a); 
		long long int sum = 0;
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
				sum += (data[j]+data[a-j-1]);
			}
			if(a%2 != 0){
				sum += data[(a/2)];
			}
			if(sum > 0){
				printf("+\n");
			}
			else if(sum == 0){
				printf("0\n");
			}
			else{
				printf("-\n");
			}
		}
	}	
}