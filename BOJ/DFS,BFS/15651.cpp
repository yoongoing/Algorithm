#include <iostream>

using namespace std;

int N,M;
int li[9];

void dfs(int cnt){
	if(cnt == M){
		for(int i=0; i<M; i++)
			cout<<li[i]<<" ";
		cout<<"\n";
		return;
	}

	for(int i=0; i<N; i++){
		li[cnt] = i+1;
		dfs(cnt+1);
	}
}

int main(int argc, char const *argv[])
{
	cin>>N>>M;
	dfs(0);
	return 0;
}