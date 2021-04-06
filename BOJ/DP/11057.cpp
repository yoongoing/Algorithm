#include <iostream>

using namespace std;

int N;
int dp[1001][10];

void DP(){
	for(int i=2; i<=N; i++){
		for(int j=0; j<10; j++){
			for(int k=0; k<=j; k++){
				dp[i][j] += dp[i-1][k];
				dp[i][j] %= 10007;
			}
		}
	}
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>N;

	for(int i=0; i<10; i++)
		dp[1][i] = 1;
	
	DP();

	int ans = 0;
	for(int i=0; i<10; i++)
		ans += dp[N][i];
	ans %= 10007;

	cout<<ans<<"\n";
	
	return 0;
}