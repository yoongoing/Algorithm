#include <stdio.h>
#include <string.h>

int main(){
	char data[1000] = {0};
	int a,i,save_1,save = 10;
	scanf("%s",data);
	a = strlen(data);
	for(i=0; i<a; i++){
		if(i == 0){
			save_1 = data[i];
		}
		else{
			if(save_1 == data[i]){
				save = save + 5;
				save_1 = data[i];
			}
			else{
				save = save + 10;
				save_1 = data[i];
			}
		}
	}
	printf("%d\n",save);
}