#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	int t,i,j;
	scanf("%d",&t);
	for(i=0; i<t; i++){
		int S_data[1000] = {0};
		int B_data[1000] = {0};

		int S_armynum, B_armynum;//S_armynum 세준이의 병사수/B_armynum 세비의 병사수 
		scanf("%d %d",&S_armynum,&B_armynum);

		for(j=0; j<S_armynum; j++){
			scanf("%d",&S_data[j]);
		}
		for(j=0; j<B_armynum; j++){
			scanf("%d",&B_data[j]);
		}
	}

	int S_cnt = 0;//세준이가 이긴횟수
	int B_cnt = 0;//세비가 이긴횟수 

	if(S_armynum>B_armynum){
		for(i=0; S_data[i]!='\0'; i++){
			
		}
	}
	else{
		for(i=0; B_data[i]!='\0'; i++){
		
		}
	}

	/*
	for(i=0; S_data[i]!='\0'; i++){
		if((S_armynum-S_cnt==1) || (B_armynum-B_cnt == 1)){
			break;
		}
		for(j=0; B_data[j] != '\0'; j++){
			if(S_data[i] != 0 && B_data[j] != 0){
				if(S_data[i] > B_data[j]){
					B_data[j] = 0;
				}
				else if(S_data[i] < B_data[j]){
					S_data[j] = 0;	
				}		
			}
			else if(S_data[i]==0 || B_data[j]==0){
				if(S_data[i] == 0){
					S_cnt++;
				}
				else if(B_data[j]==0){
					B_cnt++;
				}
			}
			
		}
	}
	if(S_armynum-S_cnt==1){
		printf("S\n");
	}
	else if(B_armynum-B_cnt == 1){
		printf("B\n");
	}
	else{
		for(i=1;i<=2;i++){
			int a = rand()%2+1;
			if(a == 1){
				printf("S\n");
			}
			else{
				printf("B\n");
			}
		}
	}
	*/
}