#include <iostream>
#include <algorithm>

#define MAX 1000
using namespace std;


int N;
int dp[MAX+1][3];
int w[MAX+1][3];

void DP(){
	for(int i=1; i<=N; i++){//i번째 집을
		//j로 칠할때의 "최소" 비용은
		//i-1번째 집의 최소비용 + i 집을 j로 칠할때 비용 
		dp[i][0] = min(dp[i-1][1],dp[i-1][2]) + w[i][0];
		dp[i][1] = min(dp[i-1][0],dp[i-1][2]) + w[i][1];
		dp[i][2] = min(dp[i-1][0],dp[i-1][1]) + w[i][2];
		
	}
}

	

int main(int argc, char const *argv[])
{

	cin>>N;

	for(int i=1; i<=N; i++){
		cin>>w[i][0]>>w[i][1]>>w[i][2];
	}
	DP();
	cout<<min(min(dp[N][0], dp[N][1]),dp[N][2])<<endl;


	return 0;

}