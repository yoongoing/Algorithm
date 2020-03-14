#include <stdio.h>

int main(){
	int i;
	int a = 0;
	int b = 0;
	int data1[4] = {0};
	int data2[3] = {0};
	for(i=0; i<3; i++){
		scanf("%d",&data1[i]);
	}
	for(i=0; i<2; i++){
		scanf("%d",&data2[i]);
	}
	for(i=0; i<3; i++){
		if(a != 0){
			if(a > data1[i]){
				a = data1[i];
			}
		}		
		if(i == 0){
			a = data1[i];
		}		
	}
	for(i=0; i<2; i++){
		if(b != 0){
			if(b > data2[i]){
				b = data2[i];
			}
		}
		if(i == 0){
			b = data2[i];
		}
	}
	printf("%d\n",a + b - 50);
}