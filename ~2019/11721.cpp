#include <stdio.h>

int main()
{
	char a[100];
	scanf("%s",a);

	int i;
	for(i=0; a[i]!='\0'; i++){
		printf("%c",a[i]);
		if((i+1) % 10 == 0) printf("\n");
	}
	return 0;
}