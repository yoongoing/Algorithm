#include <stdio.h>

int main(){
	int i,j,n;
	int data[1000001] = {0};
	scanf("%d",&n);
	for(i=0; i<n; i++){
		scanf("%d",&data[i]);
	}
	int save_data;
	for(i=0; i<n; i++){
		for(j=i+1; j<n; j++){
			if(data[i] > data[j]){
				save_data = data[i];
				data[i] = data[j];
				data[j] = save_data;
			}
		}
	}

	for(i=0; i<n; i++){
		printf("%d\n",data[i]);
	}
}