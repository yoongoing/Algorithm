#include <stdio.h>
#include <string.h>

int main(){
	int t,i,j;
	scanf("%d",&t);
	for(i=0; i<t; i++){
		int flag = 0;
		int save_data = 0;
		int count = 0;
		int countgap = 1;
		char data[100] = {0};
		scanf("%s",data);
		int length = strlen(data);
		for(j=0; j<length; j++){
			if(data[j]== 'O'){
				if(data[j] == save_data){
					flag = 1;
				}
				if(data[j]==save_data && flag==1){
					flag = 1;
					countgap++;
					count = count + countgap;
				}
				else if(data[j] != save_data) {
					flag = 0;
					countgap = 1;
					count = count + countgap;
				}
			} 
			save_data = data[j];
		}
		printf("%d\n", count);
	}
}