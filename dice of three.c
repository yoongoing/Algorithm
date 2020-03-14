#include <stdio.h>

int main(){
	int a,b,c,i,j,compare;
	int data[100] = {0};
	int check[4] = {0};
	int same = 1;
	int save = 0;
	int max = 0;
	int sum = 0;
	for(i=0; i<3; i++){
		scanf("%d",&data[i]);
	}	
	for(i=0; i<3; i++){
		if(data[i] > max){
			max = data[i];
		}
		for(j=i+1; j<3; j++){
			if(data[i] == data[j] && check[j] != 1){
				save = data[j];
				same++;
				check[j] = 1;
			}
			
		}
	
	}
	if(same == 3){
		sum = 10000 + save * 1000;
	}
	else if(same == 2){
		sum = 1000 + save * 100;
	}
	else{
		sum = max * 100;
	}
	printf("%d\n",sum );
			
}