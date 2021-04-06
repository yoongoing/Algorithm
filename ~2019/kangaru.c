#include <stdio.h>

int main(){
	int n,a,b,i;
	int data[100] = {0};
	for(i=0; i<3; i++){
		scanf("%d",&data[i]);
	}
	a = data[1] - data[0] - 1;
	b = data[2] - data[1] - 1;
	if(a > b){
		printf("%d\n",a);
	}
	else{
		printf("%d\n",b);
	}
}