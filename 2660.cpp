#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;
int n,x,y;
int matrix[52][52];
int result_row[51];


void Be_INF(){
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++)
			if(i != j && matrix[i][j]!= 1) matrix[i][j] = 999999999;
	}
}

void floydWarshall(){

	for(int k=1; k<=n; k++){ //거쳐가는 노드
		for(int i=1; i<=n; i++){ //출발 노드
			for(int j=1; j<=n; j++){ //도착노드
				if(matrix[i][k]+matrix[k][j]< matrix[i][j])
					matrix[i][j] = matrix[i][k]+matrix[k][j];
			}
		}
	}
}


int main(int argc, char const *argv[])
{
	cin>>n;
	
	for(int i=0; ; i++){
		cin>>x>>y;
		if(x == -1 && y == -1) break;
		matrix[x][y] = 1;
		matrix[y][x] = 1;
		
	}
	Be_INF();
	floydWarshall();
	
	int m = 999999999;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(i == j) continue;
			result_row[i] = max(result_row[i],matrix[i][j]);
		}
		m = min(result_row[i],m);
	}

	int total=0;

	for(int i=1; i<=n; i++)
		if(result_row[i] == m)	total++;
		 
	cout<<m <<" "<<total<<endl;
	for(int i=1; i<=n; i++)
		if(result_row[i] == m)	cout<<i<<" ";
		
	return 0;
}