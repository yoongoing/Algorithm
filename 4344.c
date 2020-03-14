#include <stdio.h>
#include <math.h>

int main(){
	int t,i,j;
	scanf("%d",&t);
	for(i=0; i<t; i++){
		int c = 0;
		int check = 0;
		int data[1000] = {0};
		int score_total=0,score=0;
		int average = 0;
		double rate = 0;
		scanf("%d",&c);
		for(j=0; j<c; j++){
			scanf("%d",&score);
			data[j] = score;
			score_total += score;
		}
		average = score_total / c;
		for(j=0; j<c; j++){
			if(data[j] > average){
				check++;				
			}
		}
		rate = (double)check * 100 / (double)c;
		printf("%.3f%%\n",rate);
	}
}