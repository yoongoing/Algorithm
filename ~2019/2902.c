#include <stdio.h>
#include <string.h>

int main(){
	char data[101] = {0};
	int i,scan;
	scanf("%s",data);
	scan = strlen(data);
	for(i=0; i<scan; i++){
		if(data[i] != '-'){
			if(data[i] - 32 < 65){
				printf("%c",data[i]);
			}
		}
	}
	return 0;
}