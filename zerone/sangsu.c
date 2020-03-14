#include <stdio.h>

int main(){
	int data1[1000] = {0};
	int data2[1000] = {0};
	int data3[1000] = {0};
	int data4[1000] = {0};
	int data5[1000] = {0};
	int a,i;
	scanf("%s",data1);
	scanf("%s",data3);
	for(i=0;i<3;i++){
		if(i=1){
			data2[i] = data1[i];
			data4[i] = data3[i];
		}
		else{
			data2[i] = 11 % data1[i];
			data4[i] = 11 % data3[i];
		}
	}
	
	if(data2[1]>data4[1]){
		a = data2[1];
	}
	else{
		a = data4[1];
	}
	for(i=0;i<3;i++){
		if(data2[i]>data4[i]){
			printf("%d\n",data2[i]);
		}
		else if(data2[i]=data4[i]){
			printf("%d\n",data2[i]);
		}
		else{
			printf("%d\n",data4[i]);
		}
	}	
	
	else if(data2[0]=data4[0]){
		if(data2[1]>data4[1] == a)
	}
	
	

}	