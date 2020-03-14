#include <stdio.h>

int double_num(int a){
	a = a * a;
	return a;
}
int main(){
	int a,n1, n2, n3, n4, n5;
	scanf("%d %d %d %d %d",&n1,&n2,&n3,&n4,&n5);
	a = double_num(n1) + double_num(n2) + double_num(n3) + double_num(n4) + double_num(n5);
	a = a % 10;
	printf("%d\n",a);
}
