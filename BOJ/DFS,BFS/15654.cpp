#include <iostream>
#include <algorithm>

using namespace std;

int N,M;
int li[9];
int ans[9];
int visited[9] = {0,};

void dfs(int cnt){
	if(cnt == M){
		for(int i=0; i<M; i++)
			cout<<ans[i]<<" ";
		cout<<"\n";
		return;
	}
	for(int i=0; i<N; i++){
		if(visited[i])
			continue;
		visited[i] = 1;
		ans[cnt] = li[i];
		dfs(cnt+1);
		visited[i] = 0;
	}
}

int main(int argc, char const *argv[])
{
	cin>>N>>M;
	for(int i=0; i<N; i++)
		cin>>li[i];
	
	sort(li,li+N);
	dfs(0);

	return 0;
}