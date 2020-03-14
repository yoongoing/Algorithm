#include <stdio.h>

int main(){
	int data[5][5] = {0};
	int data1[5] = {0};
	int data2[5] = {0};
	int data3_x[5] = {0};
	int data3_y[5] = {0};
	int a_x[3] = {0};
	int a_y[3] = {0};
	int b_x[3] = {0};
	int b_y[3] = {0};
	int a,b,c,d,width_2, width2, width3, width4, i, j;
	for(i=0; i<4; i++){
		for(j=0; j<4; j++){
			scanf("%d",&data[i][j]);
		}			
	}
	for(i=0; i<4; i++){
		if(i == 0){
			for(j=0; j<4; j++){
				data1[j] = data[i][j];
			}
		}
		else{
			//각각의 교집합 더해주기
			for(j=i+1; j<4; j++){
				int aa = 0, bb = 0;
				//x 좌표
				if(data[j][0] < data1[0] < data[j][2]){
					a_x[0] = data1[0];
					aa++;
				}
				else{
					a_x[0] = data[j][0];
					bb++;
				}

				if(data[j][0] < data1[2] < data[j][2]){
					a_x[1] = data1[2];
					aa++;
				}
				else{
					a_x[1] = data[j][2];
					bb++;
				}
				//y좌표
				if(data[j][1] < data1[1] < data[j][3]){
					a_y[0] = data1[1];
					aa++;
				}
				else{
					a_y[0] = data[j][1];
					bb++;
				}

				if(data[j][1] < data1[3] < data[j][3]){
					a_y[1] = data1[3];
					aa++;
				}
				else{
					a_y[1] = data[j][3];
					bb++;
				}
				printf("%d\n",bb);
				if(aa == 0 &&bb != 4){
					width_2 = width_2 + ((a_x[1] - a_x[0]) * (a_y[1] - a_y[0]));
				}
				
			}
			printf("%d\n",width_2);
			for(j=0; j<4; j++){
				data1[j] = data[i+1][j];
			}
		}
	}
	

		
}