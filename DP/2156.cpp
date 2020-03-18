#include <iostream>
#include <algorithm>

using namespace std;

int N;
int grape[10001];
int dp[10001];
void print(){
	for(int i=0; i<N; i++)
		cout<<dp[i]<<" ";
	cout<<endl;
}

void DP(){
	dp[0] = grape[0];
	dp[1] = max(dp[0] + grape[1],
				grape[1]);
	dp[2] = max(dp[1], max(grape[1]+grape[2],
						   	dp[0]+grape[2]));
	for(int i=3; i<=N; i++){
		dp[i] = max(dp[i-1], max(dp[i-3] + grape[i-1] + grape[i], 
								 dp[i-2] + grape[i]));
	}
}

int main(int argc, char const *argv[])
{
	cin>>N;
	for(int i=0; i<N; i++)
		cin>>grape[i];

	DP();
	cout<<dp[N]<<endl;
	return 0;
}