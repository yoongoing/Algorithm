#include <stdio.h>

int main(){
	int n,i;
	int data[1001] = {0};
	int aa;
	int a = 0;
	int b = 0;
	int num = 0;
	scanf("%d",&n);
	for(i=0; i<n; i++){
		scanf("%d",&data[i]);		
	}

	for(i=n-1; i>=0; i--){
		a = b;
		b = data[i];
		if(i != n-1){	
			if(a <= b){	//a는 b보다 커야만 한다.	
		 		while (a <= b){//a가 b보다 커질때까지 돌려야 한다.
		 				b--;
		 				num++;
				}
			}
		}
	}			
	printf("%d\n",num);
}
//이 문제는 뒤에서 부터 조져야함.