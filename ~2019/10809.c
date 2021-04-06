#include <stdio.h>
#include <string.h>

int main(){
	char data[101] = {0};
	int check[26] = {0};
	int check_index[100] = {0};
	int i,j;
	scanf("%s",data);
	int length = strlen(data);
	for(i=0; i<length; i++){
		// check[data[i] - 'a']++;
		for(j=i+1; j<length; j++){
			if(data[i] == data[j]){
				check_index[j]++;
			}
		}
	}
	for(i=0; i<length; i++){
		if(check_index[i] == 0){
			if(i == 0){
				check[data[i] - 'a'] = 99;
			}
			else{
				check[data[i] - 'a'] = i;				
			}
		}
	}	
	for(i=0; i<26; i++){
		if(check[i] == 99){
			printf("0 ");			
		}
		else if(check[i] != 0){
			printf("%d ",check[i]);
		}
		else{
			printf("-1 ");
		}
		if(i==25){
			printf("\n");
		}	
	}
}