#include <stdio.h>

int main(){
	int i,n,m,x;
	int index = 0;
	int data[10000] = {0};
	scanf("%d %d",&n,&x);
	for(i=0; i<n; i++){
		scanf("%d",&m);
		if(m < x){
			data[i] = m;
			
		}
	}
	for(i=0; i<n; i++){
		if(data[i] != 0){
			printf("%d ",data[i]);
		}
		
	}

}
