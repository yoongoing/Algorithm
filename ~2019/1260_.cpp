#include <iostream>
#include <queue>

using namespace std;

int N,M,V;
int map[1002][1002] = {0,};
int check[1002] = {0,};

void dfs(int node){
	check[node] = 1;
	cout<<node<<" ";
	
	for(int i=1; i<=N; i++){
		if((map[node][i]==1) && (check[i]==0)){
			dfs(i);
		}
	}
}

void bfs(int node){
	queue<int> q;
	
	q.push(node);
	check[node] = 1;

	while(!q.empty()){
		int n = q.front();
		cout<<n<<" ";
		q.pop();

		for(int i=1; i<=N; i++){
			if(map[n][i]==1 && (check[i]==0)){
				q.push(i);
				check[i] = 1;
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	cin>>N>>M>>V;

	for(int i=0; i<M; i++){
		int n1,n2;
		cin>>n1>>n2;
		map[n1][n2] = 1;
		map[n2][n1] = 1;
	}

	dfs(V);
	cout<<endl;

	memset(check,0,sizeof(check));

	bfs(V);
	cout<<endl;
	return 0;
}