#include <stdio.h>

int main(){
	int i,j,t,save;
	scanf("%d",&t);
	for(i=0; i<t; i++){
		int a,b,c,data1,data2,m,n,m1,m2;
		scanf("%d %d",&data1,&data2);
		a = data1;
		b = data2;
		c = a * b;
		if(a == b){
			printf("%d %d\n",a,b);
		}
		else if(a > b){
			while(1){
				m = data1 / data2;
				n = data1 % data2;
				if(n == 0){
					break;
				}
				data1 = data2;
				data2 = n;
			}
			if(m == 1){
				printf("%d 1\n",c);
			}
			else{
				m1 = b / data2;
				m2 = a / data2;
				printf("%d %d\n",data2*m1*m2,data2);
			}
		}
		else{
			while(1){
				m = data2 / data1;
				n = data2 % data1;
				if(n == 0){
					break;
				}
				data2 = data1;
				data1 = n;
			}
			if(m == 1){
				printf("%d 1\n",c);
			}
			else{
				m1 = b / data1;
				m2 = a / data1;
				printf("%d %d\n",data1*m1*m2,data1);
			}
		}
		
	}
}