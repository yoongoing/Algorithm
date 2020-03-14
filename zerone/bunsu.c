#include <stdio.h>

int main(){
	int i,j,n,count;
	count = 1;
	i = 1;
	j = 1;
	scanf("%d",&n);
	if(n==1){
		printf("1/1");
	}
	while (count<n){			
		if(i==j){
			i=1;
			j++;
			count ++;
		}
		else if(i<j){
			i++;
			count ++;
		}
	}
	if(n != 1){
		printf("%d/%d\n",i,j);		
	}

		
}