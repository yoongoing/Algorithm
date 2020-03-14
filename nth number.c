#include <stdio.h>

int main(){
	int n,i,j,k;	
	scanf("%d",&n);
	for(i=0; i<n; i++){
		int data[100] = {0};
		int data_compare = 0;
		int data_rest;
		for(j=0; j<10; j++){
			scanf("%d",&data[j]);
		}
		for(j=0; j<10; j++){
			for(k=j+1 ; k<10; k++){
				data_compare = data[i];
				if(data[k] < data[j]){
					data_rest = data[k];
					data[k] = data[j];
					data[j] = data_rest;
				}
			}
		}
		printf("%d\n",data[7]);
	}
}
