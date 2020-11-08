#include <iostream>

using namespace std;

int N,M;
int li[9];
int visited[9] = {0,};

void dfs(int cnt, int idx){
	if(cnt == M){
		for(int i=0; i<M; i++)
			cout<<li[i]<<" ";
		cout<<"\n";
		return;
	}

	for(int i=idx+1; i<N; i++){
		if(visited[i])
			continue;
		visited[i] = 1;
		li[cnt] = i+1;
		dfs(cnt+1, i);
		visited[i] = 0;
	}
}

int main(int argc, char const *argv[])
{
	cin>>N>>M;
	dfs(0, -1);
	return 0;
}