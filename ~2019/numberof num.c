#include <stdio.h>

int main(){
	int i,a,b,c,total,x,y;
	int num;
	int data[100] = {0};
	int check[10] = {0};
	scanf("%d %d %d",&a,&b,&c);
	total = a * b * c;
	while (total > 0){
		x = total % 10;
		check[x] = check[x] + 1;
		total = total / 10;
	}
	for(i=0; i<10; i++){
		printf("%d\n",check[i]);
	}

}