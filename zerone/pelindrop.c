#include <stdio.h>
#include <string.h>

int main(){
	int i;
	int z = 0;
	char data[1000];

	scanf("%s",data);
	for(i=0;i<strlen(data)/2;i++){
		if(data[i]==data[strlen(data)-i-1]){
			z++;
		}
	}
	if(z == strlen(data)/2){
		printf("Yes\n");
	}
	else{
		printf("No\n");
	}
}