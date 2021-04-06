#include <iostream>
#include <cstring>

using namespace std;
#define MAX 51

int N,M;
int map[MAX][MAX];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = { 0, 1, 0,-1};

int total = 0;

void dfs(int x, int y, int dir){
	if(map[x][y] == 0){
		map[x][y] = 2;
		total++;	
	}
	
	
	for(int i=0; i<4; i++){
		int n_dir = (dir + 3 - i) %4;

		int nx = x + dx[n_dir];
		int ny = y + dy[n_dir];
		
		if(nx < 0 || ny < 0 || (nx >= N) || ny >= M) 
			continue;

		if(map[nx][ny] == 0)
			dfs(nx,ny,n_dir);
	}
				
	
	int n_dir = (dir+2)%4;
	
	int nx = x + dx[n_dir];
	int ny = y + dy[n_dir];
	

	if(map[nx][ny]==1){
		cout<<total<<endl;
		exit(0);
	}

	dfs(nx,ny,dir);
}

int main(int argc, char const *argv[])
{
	int r,c,d;
	cin>>N>>M>>r>>c>>d;

	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			cin>>map[i][j];

	dfs(r,c,d);

	return 0;
}