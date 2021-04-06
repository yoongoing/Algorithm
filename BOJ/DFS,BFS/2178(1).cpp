#include <iostream>
#include <string>
#include <queue>

using namespace std;

int N,M;
int map[101][101];

int dy[4] = {0,0,-1,1};
int dx[4] = {-1,1,0,0};

int bfs(int y, int x){
	int check[101][101] = {0,};
	queue<pair<int, int> > q;
	
	q.push(make_pair(y,x));
	check[y][x] = 1;

	while(!q.empty()){
		y = q.front().first;
		x = q.front().second;
		q.pop();

		for(int i=0; i<4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];

			if((ny<1) || (nx<1) || (ny>N) || (nx>M))
				continue;

			if(check[ny][nx] != 0)
				continue;
			if(map[ny][nx] == 1){
				q.push(make_pair(ny,nx));
				check[ny][nx] = check[y][x] + map[ny][nx];	
			} 
		}
	}

	return check[N][M];
}
int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>N>>M;

	for(int i=1; i<=N; i++){
		string str;
		cin>>str;

		for(int j=0; j<M; j++)
			map[i][j+1] = str[j] - '0'; 
	}
			
	int cnt = bfs(1,1);
	cout<<cnt<<"\n";
	return 0;
}