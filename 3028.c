#include <stdio.h>
#include <string.h>
int main(){
	int data1[4] = {0};
	char data2[50] = {0};
	int i,scan,save;
	scanf("%s",data2);
	data1[0] = 1;
	scan = strlen(data2);
	for(i=0; i<scan; i++){
		if(data2[i] == 'A'){
			save = data1[0];
			data1[0] = data1[1];
			data1[1] = save;
		}
		else if(data2[i] == 'B'){
			save = data1[1];
			data1[1] = data1[2];
			data1[2] = save;
		}
		else{
			save = data1[0];
			data1[0] = data1[2];
			data1[2] = save;
		}
	}
	for(i=0; i<3; i++){
		if(data1[i] == 1){
			printf("%d\n",i+1);
		}
	}
}