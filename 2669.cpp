#include <stdio.h>
#include <string>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>


using namespace std;

// void prints(int (*check)[100]){
// 	for(int i=0; i<100; i++){
// 		for (int j=0; j<100; j++){
// 			cout<<check[i][j];
// 		}
// 		cout<<endl;
// 	}
// }


int main(int argc, char const *argv[])
{
	int x1,y1,x2,y2;
	int total=0;
	int check[100][100] = {0};


	for(int i=0; i<4; i++){
		cin >> x1 >> y1 >> x2 >> y2;
		
		for(int j=x1; j<x2; j++)
			for(int k=y1; k<y2; k++)
				if(check[j][k] == 0){
					check[j][k] = 1;
					total++;
				}
	}
	// prints(check);

	cout<<total; 


	return 0;
}