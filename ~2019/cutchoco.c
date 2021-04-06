#include <stdio.h>

int main(){
	int n,m,a;
	scanf("%d %d",&n,&m);
	if(n < m){
		a = (n - 1) + n * (m - 1);
	}
	else if(n > m){
		a = (m - 1) + m * (n - 1);
	} 
	else{
		a = (m - 1) + n * (m - 1);
	}
	printf("%d\n",a);
}
