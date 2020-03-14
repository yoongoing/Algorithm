#include <stdio.h>

int main(){
	int n,i;
	int a = 0;
	int index = 0;
	int high_biggest = 0;
	int high = 0;
	int data1[1001] = {0};
	int data2[1001] = {0};
	scanf("%d",&n);
	for(i=0; i<n; i++){
		scanf("%d",&data1[i]);
	}
	for(i=0; i<n; i++){
		if(a != 0){
			if(a < data1[i]){
				index++;
				data2[i] = data1[i];
				a = data1[i];
				high = data2[i] - data2[i-index];				
				if(high_biggest < high){
					high_biggest = high;
				}				
				
			}
			else{
				high = data2[i-1] - data2[i-1-index];
				if(high_biggest < high){
					high_biggest = high;
				}				
				a = data1[i];
				data2[i] = a;
				index = 0;
			}
		}
		if(i == 0){
			a = data1[i];
			data2[i] = a;
		}
	}
	printf("%d\n",high_biggest);



}