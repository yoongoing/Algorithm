#include <iostream>

using namespace std;

int N,M;
int map[1001][1001] = {0,};
int dp[1001][1001] = {0,};


int DP(){
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			int next = max(max(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]);
			dp[i][j] = next + map[i][j];
		}
	}

	return dp[N][M];
}


int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>N>>M;
	for(int i=1; i<=N; i++)
		for(int j=1; j<=M; j++)
			cin>>map[i][j];

	cout<<DP()<<"\n";

	return 0;
}