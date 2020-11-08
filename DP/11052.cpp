#include <iostream>

using namespace std;

int N;
int cost[1001];
int dp[1001];

int DP(){
	cost[0] = dp[0] = 0;

	for(int i=1; i<=N; i++){
		for(int j=1; j<=i; j++){
			dp[i] = max(dp[i], dp[i-j] + cost[j]);
		}
	}

	return dp[N];
}


int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>N;
	for(int i=1; i<=N; i++)
		cin>>cost[i];

	cout<<DP()<<"\n";

	return 0;
}