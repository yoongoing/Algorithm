#include <iostream>

using namespace std;

int N,M;
int li[9];
int visited[9] = {0,};

void dfs(int cnt){

	if(cnt == M){
		for(int i=0; i<M; i++){
			cout<<li[i]<<" ";
		}
		cout<<"\n";
		return;
	}
	
	for(int i=0; i<N; i++){
		if(!visited[i]){
			visited[i] = 1;
			li[cnt] = i+1;
			dfs(cnt + 1);
			visited[i] = 0;
		}
	}

}

int main(int argc, char const *argv[])
{
	cin>>N>>M;

	dfs(0);
	return 0;
}