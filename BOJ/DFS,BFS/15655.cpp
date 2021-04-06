#include <iostream>
#include <algorithm>

using namespace std;

int N,M;
int li[9];
int ans[9];

void dfs(int cnt, int idx){
	if(cnt == M){
		for(int i=0; i<M; i++)
			cout<<ans[i]<<" ";
		cout<<"\n";
		return;
	}

	for(int i=idx+1; i<N; i++){
		ans[cnt] = li[i];
		dfs(cnt+1, i);
	}
}
int main(int argc, char const *argv[])
{
	cin>>N>>M;
	for(int i=0; i<N; i++)
		cin>>li[i];

	sort(li,li+N);
	dfs(0,-1);
	return 0;
}