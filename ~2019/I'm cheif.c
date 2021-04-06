#include <stdio.h>

int main(){
	int i,j;
	int total = 0;
	int index = 0;
	int data1[100][100] = {0};
	int data2[100] = {0};
	for(i=0; i<5; i++){
		for(j=0; j<4; j++){
			scanf("%d",&data1[i][j]);
		}
	}
	for(i=0; i<5; i++){
		for(j=0; j<4; j++){
			data2[i] = data2[i] + data1[i][j];			  
		}
	}
	for(i=0; i<5; i++){		
		if(total != 0){
			if(data2[i]>total){
				total = data2[i];
				index = i;
			}
		}
		if(i == 0){
			total = data2[i];
		}
	}
	printf("%d %d",index+1,total);
	return 0;

} 