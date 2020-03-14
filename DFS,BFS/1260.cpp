#include <cstring>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int map[1002][1002] = {0,};
bool d_check[1002] = {0,};
bool b_check[1002] = {0,};


queue<int> q;

int N,M,V;


void DFS(int s){
	cout<<s<<" ";
	d_check[s] = true;

	for(int j=1; j<=N; j++){
		if(map[s][j] == 1 && !d_check[j]){
			DFS(j);
		}
	}
	
	return;
}

void BFS(int s){
	b_check[s] = true;
	q.push(s);

	while(!q.empty()){
		s = q.front();
		q.pop();
		cout<<s<<" ";
		for(int i=1; i<=N; i++){
			if(map[s][i] == 1 && !b_check[i]){
				b_check[i] = true;
				q.push(i);
			}
		}
	}
	
	return;
}
int main(int argc, char const *argv[])
{

	cin>>N>>M>>V;

	for(int i=0; i<M; i++){
		int x1,x2;
		cin>>x1>>x2;
		map[x1][x2] = 1;
		map[x2][x1] = 1;
	}
	DFS(V);	
	cout<<endl;
	
	BFS(V);
	cout<<endl;
	return 0;
}