#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin>>n;

	int a[1001];
	int dp[1001];
	vector<int> lis[1001];
	vector<int> ans;

	for(int i=0; i<n; i++){
		cin>>a[i];
		dp[i] = 0;
	}

	for(int i=0; i<n; i++){
		dp[i] = 1;
		lis[i].push_back(a[i]);
		for(int j=0; j<i; j++){
			if(a[i] > a[j] && dp[i] < dp[j]+1){
				lis[i].clear();
				lis[i] = lis[j];
				lis[i].push_back(a[i]);
				dp[i]++;
			}
		}

		if(lis[i].size() > ans.size()){
			ans = lis[i];
		}
	}

	cout<<ans.size()<<"\n";

	for(int i=0; i<ans.size(); i++){
		cout<<ans[i]<<" ";
	}
	cout<<"\n";

	return 0;
}