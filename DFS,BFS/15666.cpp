#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N,M;
int v[9];
int ans[9];

void dfs(int cnt, int idx){
	if(cnt == M){
		for(int i=0; i<M; i++)
			cout<<ans[i]<<" ";
		cout<<"\n";
		return;
	}
	int prev = -1;

	for(int i=idx; i<N; i++){
		if(prev == v[i])
			continue;

		prev = v[i];
		ans[cnt] = v[i];
		dfs(cnt+1, i);
	}
}

int main(int argc, char const *argv[])
{
	cin>>N>>M;

	for(int i=0; i<N; i++)
		cin>>v[i];

	sort(v, v+N);
	dfs(0, 0);
	return 0;
}