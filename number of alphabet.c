#include <stdio.h>
#include <string.h>

int main(){
	int i;
	char data[1000] = {0};
	char check[26] = {0};
	scanf("%s",data);
	for(i=0; i<strlen(data); i++){
		check[data[i] - 'a'] = check[data[i] - 'a'] + 1;
	} 
	for(i=0; i<26; i++){
		printf("%d ",check[i]);
	}
}