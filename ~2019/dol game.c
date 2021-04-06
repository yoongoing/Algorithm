#include <stdio.h>

int main(){
	int n,sang,chang;
	int even_odd = 1;
	scanf("%d",&n);
	while(n > 0){
		n--;
		even_odd++;
	}
	if (even_odd % 2 == 0){
		printf("SK\n");
	}
	else{
		printf("CY\n");
	}
}