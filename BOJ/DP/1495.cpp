#include <iostream>
#include <cstring>
#include <algorithm>

#define MAX 100
#define MAX_VOL 1000

using namespace std;

int N,S,M;
int volume[MAX+1] = {0,};
int dp[MAX+1][MAX_VOL+1] = {0,};

int multi(int x){
	int result = 1;
	for(int i=0; i<x; i++)
		result*= 2;
	return result;
}

int next_vol(int i, int x, int temp){
	if(i == 0) {
		return temp - volume[x];
	}
	return temp + volume[x];
}

int main(int argc, char const *argv[])
{
	cin>>N>>S>>M;

	for(int i=1; i<=N; i++){
		cin>>volume[i];
	}

	
	dp[0][S] = 1;

	for(int i=1; i<=N; i++){
		for(int j=0; j<=M; j++){
			if(dp[i-1][j] == 1){
				for(int k=0; k<2; k++){
					int next = next_vol(k,i,j);
					if(next>= 0 && next<=M)
						dp[i][next] = 1;
				}
			}
		}
	}


	int max = -1;
	for(int j=0; j<=M; j++){
		if(dp[N][j]){
			if(max < j) max = j;
		}
	}
	cout<<max<<endl;

	return 0;
}