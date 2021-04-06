#include <stdio.h>
#include <cstring>
#include <iostream>

using namespace std;
void init_2(int (*arr)[22]){
	for(int i=0; i<20; i++){
		for(int j=0; j<20; j++){
			arr[i][j] = 2;
		}
	}
}


void prints(int (*arr)[22], int n){
	for(int i=0; i<n; i++){
		for(int j=0; j<n-i; j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
}
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int sum=0;
	int total=0;
	int row[22][22] ={0,};
	int column[22][22]={0,};

	int row_index[22] = {0,};
	int column_index[22]={0,};

	int matrix[22][22];
	init_2(matrix);


	for(int i=0; i<n; i++){
		int y;
		cin >> y;
		for(int j=0; j<y ; j++){
			cin>>row[i][j];
			sum += row[i][j];
		}
	}

	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		for(int j=0; j<x ; j++){
			cin >> column[i][j];
		}
	}



	for(int y=0; y<n; y++){
		
		for(int x=0; x<n; x++){
			// cout<<"Current matrix index is "<<y<<", "<<x<<endl;
			int r_index = row_index[y]; 
			int c_index = column_index[x];
			//cout<<"(row_index["<<y<<"], column_index["<<x<<"]) : "<<"("<<r_index<<", "<<c_index<<")"<<endl;
			//cout<<"{row["<<y<<"]["<<r_index<<"], column["<<x<<"]["<<c_index<<"]) : "<<"("<<row[y][r_index]<<", "<<column[x][c_index]<<")"<<endl;
			if(row[y][r_index] > 0 && column[x][c_index] > 0 && matrix[y][x] == 2){
				row[y][r_index]--;
				column[x][c_index]--;
				matrix[y][x] = 1;
				total++;
			}
			else if(row[y][r_index] == 0 || column[x][c_index] == 0) matrix[y][x] = 0;
			else if(matrix[y][x] == 0){
				continue;
			}
			
			if(row[y][r_index] == 0){ 
				matrix[y][x+1] = 0;
				row_index[y]++;
			}
		
			if(column[x][c_index] == 0){
				matrix[y+1][x] = 0;
				column_index[x]++;	
			} 

			
		}
	}
	if(sum == total) prints(matrix,n);
	else cout<<"No Answer";
	

	
	

	return 0;
}