#include <stdio.h>

int main(){
	int t,i,j,k;
	scanf("%d",&t);
	int max_1 = 0;
	for(i=0; i<t; i++){
		int data[100] = {0};
		int check[4] = {0};
		int same = 1;
		int save = 0;
		int save1 = 0;
		int max = 0;

		int sum = 0;
		for(j=0; j<3; j++){
		scanf("%d",&data[j]);
		}	
		for(j=0; j<3; j++){
			if(data[j] > max){
				max = data[j];
			}
			for(k=j+1; k<3; k++){
				if(data[j] == data[k] && check[k] != 1){
					save = data[k];
					same++;
					check[k] = 1;
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
		if(sum > max_1){
			max_1 = sum;
		}
		
	}
	printf("%d\n",max_1);			

}
