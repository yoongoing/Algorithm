#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T,n;
	cin>>T;

	for(int test=T; test>0; test--){
		cin>>n;
		
		int map[2][100001];
		int dp[2][100001];

		for(int i=0; i<=1; i++)
			for(int j=1; j<=n; j++)
				cin>>map[i][j];
			
		dp[0][0] = dp[1][0] = 0;
		dp[0][1] = map[0][1];
		dp[1][1] = map[1][1];

		for(int j=2; j<=n; j++){
			dp[0][j] = max(dp[1][j-1], dp[1][j-2]) + map[0][j];
			dp[1][j] = max(dp[0][j-1], dp[0][j-2]) + map[1][j];
		}

		cout<<max(dp[0][n], dp[1][n])<<"\n";
	}

	return 0;
}