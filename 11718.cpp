#include <stdio.h>

int main()
{
	char a[101];
	while(scanf("%[^\n]s",a) != -1){
		getchar();
		printf("%s\n",a);
	}
	return 0;
}