#include <iostream>
#include <queue>

#define MAX 8
using namespace std;

int N,M;
int map[MAX][MAX];
int virus[MAX][MAX];

int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

void BFS(int y, int x){
	queue <pair<int, int> > q;
	q.push(make_pair(y,x));

	while(!q.empty()){
		y = q.front().first;
		x = q.front().second;
		q.pop();

		if(map[y][x] == 2){
			for(int i=0; i<4; i++){
				int ny = y + dy[i];
				int nx = x + dx[i];

				if(범위안에 안들어간다면){
					continue;
				}
				if(ny != )	
				q.push(make_pair(ny,nx));
			}
		}		
	}
}


int main(int argc, char const *argv[])
{
	cin>>N>>M;

	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cin>>map[i][j];
		}
	}

	BFS(0,0);

	return 0;
}