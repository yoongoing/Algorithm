#include <stdio.h>
int sum(int s[], int (*s2)[501],int t){
	int total = 0;
	for(int i=0; i<t; i++){
		total += s[i];
		for(int j=0; j<t; j++){
			if(s2[i][j]!= 0){
				total += s[s2[i][j]-1];
			}
		}
	}
	return total;
}

int main(){
	int data[501] = {0};
	int data2[501][501] = {0};
	int t;
	scanf("%d",&t);
	int i,j;
	for(i=0; i<t; i++){
		scanf("%d",&data[i]);
		for(j=0; ;j++){
			scanf("%d",&data2[i][j]);
			if(data2[i][j] == -1){
				data2[i][j] = 0;
				break;
			}
		}
	}
	for(i=0; i<t; i++){
		int sum = 0;
		sum += data[i];
		for(j=0; j<t; j++){
			if(data2[i][j] != 0){
				return sum(data,data2,t);

			}
			
		}
		printf("%d\n",sum);

	}
}