#include <stdio.h>

int main(){
	int n,a,i,j,r;
	int compare = 0;
	int same = 0;
	int data[100] = {0};

	int check[100] = {0};

	for(i=0; i<10; i++){
		scanf("%d",&a);	
		r = a % 42;
		data[i] = r;		
	}
	for(i=0; i<10; i++){
		compare = data[i];
		check[i] = 1;		
		for(j=i+1; j<10; j++){
			if(compare == data[j] && check[j] != 1){
				same++;	
				check[j] = 1;						
			}								
		}				
	}
	printf("%d\n",10 - same);
}