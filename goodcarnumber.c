#include <stdio.h>
#include <string.h>
#include <math.h>

int dou(int x, int y){
	int i;
	int xx = x; 
	for(i=1; i<y; i++){
		x = xx * x;
	}
	if(y == 0){
		return 1;
	}
	return x;
}

int main(){
	int n,i,j,a,b,c,d;
	char data[100] = {0};
	int check[4] = {0};
	scanf("%d",&n);
	for(i=0; i<n; i++){
		int total = 0;
		int total_2 = 0;
		int total_final = 0;
		scanf("%s",data);
		for(j=0; j<3; j++){
			check[j] = data[j] - 'A';
		}			
		for(j=4; j<8; j++){
			c = j - 4;
			total_2 = total_2 + (data[j] - '0') * (1000 / dou(10,c));
		}
		for(j=0; j<3; j++){
			d = 2-j;
			total = total + check[j] * dou(26,d);
		}
		total_final = total - total_2;
		if(total_final < 0){
			total_final = -total_final;
		}
			
		if(total_final <= 100){
			printf("nice\n");
		}
		else{
			printf("not nice\n");
		}

	}		
}
/*
#include<stdio.h>

int abs(int x){
	if (x < 0) return x*-1;
	else return x;
}
int main(){
	int n;
	scanf("%d", &n);
	int i;
	for (i = 0; i < n; i++){
		scanf("\n");
		char a, b, c, s;
		int x, y, z;
		int d;
		scanf("%c%c%c%c%d", &a, &b, &c, &s, &d);
		x = (a - 'A') * 676;
		y = (b - 'A') * 26;
		z = (c - 'A');
		if (abs(x + y + z - d) <= 100)
			printf("nice\n");
		else
			printf("not nice\n");
	}
	return 0;
}
*/