#include <stdio.h>

int main(){
	int a_x = 0;
	int a_y = 1;
	int a_z = 0;//출력될 예정
	int b_x = 0;
	int b_y = 1;
	int b_z = 0;//출력될 예정
	int k,k1,k2;
	scanf("%d",&k);
	if(k == 1){
		while(k > 0){
			b_z = b_y;
			b_y = b_x + b_z;
			b_x = b_z;
			k--;
		}
		printf("%d %d\n",a_z,b_z);	
	}
	else{
		k1 = k-1;
		while(k1 > 0){
			a_z = a_y;
			a_y = a_x + a_z;
			a_x = a_z;
			k1--;
		}
		while(k > 0){
			b_z = b_y;
			b_y = b_x + b_z;
			b_x = b_z;
			k--;
		}
		printf("%d %d\n",a_z,b_z);		
	}
}


