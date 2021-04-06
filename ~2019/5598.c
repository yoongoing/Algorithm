#include <stdio.h>
#include <string.h>

int main(){
	char data1[1010] = {0};
	int i,a;
	scanf("%s",data1);
	a = strlen(data1);
	for(i=0; i<a; i++){
		if(data1[i] == 'A'){
			printf("X");
		}
		else if(data1[i] == 'B'){
			printf("Y");
		}
		else if(data1[i] == 'C'){
			printf("Z");
		}
		else{
			printf("%c",data1[i] - 3);
		}
	}
}