#include <stdio.h>

int main(){
	int i;
	int data1[10] = {0};
	int data2[10] = {0};
	for(i=0; i<6; i++){
		scanf("%d",&data1[i]);
		if(i==0 || i==1){
			if(data1[i] != 1){				
				data2[i] = 1 - data1[i];
			}
		}	
		
		else if(i==2 || i==3 || i==4){
			if(data1[i] != 2){				
				data2[i] = 2 - data1[i];
				
			}	
		}
		else{
			if(data1[i] != 8){				
				data2[i] = 8 - data1[i];
				
			}	
		}
	}

	for(i=0; i<6; i++){
		printf("%d\n",data2[i]);
	}
}