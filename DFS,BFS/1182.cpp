#include <iostream>

using namespace std;

int n,s;
int li[21];
int check[21] = {0,};
int total = 0;

void dfs(int idx, int sum){
	if(idx == n)
		return;
	if(sum+li[idx] == s)
		total++;

	dfs(idx+1, sum);ㅜ
	dfs(idx+1, sum+li[idx]);
	
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>n>>s;
	for(int i=0; i<n; i++)
		cin>>li[i];
	
	dfs(0,0);
	
	cout<<total<<"\n";

	return 0;
}
