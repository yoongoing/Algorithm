#include <stdio.h>
#include <string.h>

int main(){
	char data[100] = {0};
	int i,j,save,scan;
	scanf("%s",data);
	scan = strlen(data);
	for(i=0; i<scan; i++){
		for(j=i+1; j<scan; j++){
			if(data[i] < data[j]){
				save = data[i];
				data[i] = data[j];
				data[j] = save;
			}
		}
	}
	printf("%s\n",data);
}