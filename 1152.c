#include <stdio.h>
#include <string.h>

int main(){
	char data[1000000] = {0};
	gets(data);
	int i;
	int length = strlen(data);
	int count = 1;

	if(length == 0){
		count = 0;
	}
	else{
		for(i=0; i<length; i++){
			if(data[i] == ' '){
				count++;
			}
		}
	}
	if(data[0] == ' ')
		count--;
		
	if (data[length - 1] == ' ')
		count--;
	printf("%d\n",count);

}