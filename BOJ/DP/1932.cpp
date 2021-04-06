#include <iostream>
#include <algorithm>

#define MAX 500
using namespace std;

int N;

int DP[MAX][MAX];

void dp(){
	for(int i=1; i<N; i++){
		for(int j=0; j<=i; j++){
			if(j == 0){
				DP[i][j] += DP[i-1][j]; 
			}
			else if(j == i){
				DP[i][j] += DP[i-1][j-1];
			}
			else {
				DP[i][j] = max(DP[i][j]+DP[i-1][j-1] , DP[i][j]+DP[i-1][j]);
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	cin>>N;
	for(int i=0; i<N; i++){
		for(int j=0; j<=i; j++)
			cin>>DP[i][j];
	}
	dp();

	int result = DP[N-1][0];
	for(int i=0; i<N; i++){
		result = max(result, DP[N-1][i]);
	}
	cout<<result<<endl;
	return 0;
}