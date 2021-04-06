#include <stdio.h>

int main(){
	int t,i,j;
	scanf("%d",&t);
	for(i=0; i<t; i++){
		int a = 0;
		int b = 0;
		int index = 0;
		int data1[1000] = {0};
		int data2[8] = {0}; 
		for(j=0; j<7; j++){
			scanf("%d", &data1[j]);
			if(data1[j] % 2 == 0){				
				a = a + data1[j]; 
				data2[index] = data1[j];
				index++;
			}
		}
		b = data2[0];
		for(j=0; j<7; j++){
			if(data2[j] != 0){
				if(b > data2[j]){
					b = data2[j];
				}
			}
		}
		printf("%d %d\n",a,b);
	}
}