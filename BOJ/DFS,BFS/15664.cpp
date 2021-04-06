#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,M;
int v[9];
int ans[9];
int visit[9];

void dfs(int cnt, int idx){
	if(cnt == M){
		for(int i=0; i<M; i++)
			cout<<ans[i]<<" ";
		cout<<"\n";
		return;
	}
	int prev = -1;
	for(int i=idx+1; i<N; i++){
		if(visit[i] || (prev==v[i]))
			continue;
		visit[i] = 1;
		prev = v[i];
		ans[cnt] = v[i];
		dfs(cnt+1, i);
		visit[i] = 0;
	}
}

int main(int argc, char const *argv[])
{
	cin>>N>>M;
	for(int i=0; i<N; i++)
		cin>>v[i];
	

	sort(v, v+N);
	dfs(0, -1);
	return 0;
}