#include <stdio.h>

int main(){
	int t,i,j,a,b;
	scanf("%d",&t);
	for(i=0; i<t; i++){
		scanf("%d %d",&a,&b);
		int c = a;
		for(j=1; j<b; j++){
			c = c * a % 10;
		}
		if(c == 0){
			printf("10\n");
			continue;
		}
		printf("%d\n",c);
	}
}