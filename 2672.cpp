#include <stdio.h>
#include <cstring>
#include <iostream>
#include <math.h>

using namespace std;
double arr[30][4];


void check(double x, double y)




int main(int argc, char const *argv[])
{
	int N;
	cin>>N;
	double x1,y1, width,height;
	
	double line[30][4];

	for(int i=0; i<N; i++){
		cin >> x1 >> y1 >> width >> height;
		arr[i][0] = x1;			//x1
		arr[i][1] = y1;			//y1
		arr[i][2] = x1 + width;	//x2
		arr[i][3] = y1 + height;//y2

		line[i][0] = arr[i][0]; //left
		line[i][1] = arr[i][1]; //down
		line[i][2] = arr[i][2]; //right
		line[i][3] = arr[i][3]; //up
	}

	for(int i=0; i<N; i++){
		current_x = 
		
		for(int j=0; j<N; j++){
			//arr[j][0] == x3
			//arr[j][1] == y3
			//arr[j][2] == x4
			//arr[j][3] == y4
			if(arr[j][0]<left){
				width = abs(left - arr[j][0])		//x1-x3
				height = abs(arr[j][3] - arr[j][1]);//y4-y3
				sum += width * height;
			}	
			if(arr[j][1]<down){
				width = abs(arr[j][2] - arr[j][0]);	//x4-x3
				height = abs(down - arr[j][1]);		//y1-y3
				sum += width * height;
			}
			if(arr[j][2]>right){
				width = abs(arr[j][2] - right);		//x4-x2
				height = abs(arr[j][3] - arr[j][1]);//y4-y3
				sum += width * height;
			}
			if(arr[j][3]>up){
				width = abs(arr[j][2] - arr[j][0]);	//x4-x3
				height = abs(arr[j][3] - up);		//y4-y2						//y4-y2
				sum += width * height;

			}
		}
	}

	// for(int i=0; i<N; i++){
	// 	cout<<arr[i][0]<<" "<<arr[i][1]<<" "<<arr[i][2]<<" "<<arr[i][3]<<endl;
	// }

	return 0;
}