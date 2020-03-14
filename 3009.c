#include <stdio.h>

int main(){
	int i,x,y,x_in,y_in;
	int data_x[1000] = {0};
	int check_x[1000] = {0};
	int check_y[1000] = {0};
	for(i=0; i<3; i++){
		scanf("%d %d",&x,&y);
		check_x[x]++;
		check_y[y]++; 
	}
	int save_x,save_y;
	for(i=0; i<1000; i++){
		if(check_y[i] == 1){
			save_y = i;
		}
		if(check_x[i] == 1){
			save_x = i;
		}
		
	}
	printf("%d %d",save_x,save_y);
}