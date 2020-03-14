#include <stdio.h>
#include <string.h>

int main(){
	char data[1000] = {0};
	int i;
	scanf("%s",data);
	for(i=0;i<strlen(data);i++){
		if(data[i]>=97){
			data[i] = data[i] - 32;
		}
		else if(data[i]<97){
			data[i] = data[i] + 32;
		}
	}
	printf("%s",data);
}