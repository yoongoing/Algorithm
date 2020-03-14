#include <stdio.h>

int main(){
	int n,i;
	int data[10];
	int a = 0;
	int aa = 8;
	for(i=0; i<8; i++){
		scanf("%d",&data[i]);
		if(i+1 == data[i]){
			a++;
		}
		else if(8-i == data[i]){
			aa--;
		}
	}
	if(a == 8){
		printf("ascending\n");
	}
	else if(aa == 0){
		printf("descending\n");
	}
	else {
		printf("mixed\n");
	}
	
		
}