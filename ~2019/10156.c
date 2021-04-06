#include <stdio.h>

int main(){
	int save,snack,number,money;
	scanf("%d %d %d",&snack,&number,&money);
	save = snack * number - money;
	if(save > 0){
		printf("%d\n",save);
	}
	else{
		printf("0\n");
	}
}