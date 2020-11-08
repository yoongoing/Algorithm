#include <iostream>
#include <algorithm>

using namespace std;

int N,M;
int li[9];
int ans[9];

void dfs(int cnt){
	if(cnt == M){
		for(int i=0; i<M; i++)
			cout<<ans[i]<<" ";
		cout<<"\n";
		return;
	}
	for(int i=0; i<N; i++){
		ans[cnt] = li[i];
		dfs(cnt+1);
	}
}

int main(int argc, char const *argv[])
{
	cin>>N>>M;
	for(int i=0; i<N; i++)
		cin>>li[i];

	sort(li, li+N);
	dfs(0);
	return 0;
}