#include <stdio.h>
#include <string.h>

int main(){
	char data[1] = {0};
	scanf("%s",data);
	int i,len = strlen(data);
	for(i=0; i<len; i++){
		printf("%d\n",data[i]);
	}
}