#include <stdio.h>

int main(){
	int n,i;
	char data1[100] = {0};
	int vote[2] = {0};
	scanf("%d",&n);
	scanf("%s",data1);
	for(i=0; i<n; i++){
		vote[data1[i] - 'A']++;
	}
	if(vote[0] > vote[1]){
		printf("A\n");
	}
	else if(vote[0] == vote[1]){
		printf("Tie\n");
	}
	else{
		printf("B\n");
	}
}