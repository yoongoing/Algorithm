#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

int N,M;
int map[9][9];
vector<pair<int, int> > v;
int v_size;

int dy[4] = {0,0,-1,1};
int dx[4] = {-1,1,0,0};

int result = -1;

int bfs(int y, int x){
	int check[9][9] = {0,};
	queue<pair<int, int> > q;


	for(int i=0; i<v_size; i++){
		q.push(make_pair(v[i].first, v[i].second));
		check[v[i].first][v[i].second] = 1;
	}

	int cpy_map[9][9];
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			cpy_map[i][j] = map[i][j];

	while(!q.empty()){
		y = q.front().first;
		x = q.front().second;
		q.pop();

		for(int i=0; i<4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];

			if((ny<0) || (nx<0) || (ny>=N) || (nx>=M))
				continue;

			if(map[ny][nx]==0 && check[ny][nx]==0){
				q.push(make_pair(ny,nx));
				map[ny][nx] = 2;
				check[ny][nx] = 1;	
			}
		}
	}

	int safe_zone = 0;
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			if(map[i][j] == 0)
				safe_zone++;
	
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			map[i][j] = cpy_map[i][j];

	return safe_zone;
}

void dfs(int cnt, int y, int x){
	if(cnt == 3){
		int safe_zone = bfs(-1,-1);
		result = max(result, safe_zone);
		return;
	}

	for(int i=y; i<N; i++){
		for(int j=0; j<M; j++){
			if((i==y) && (j<=x)){ //지금 세웠거나, 예전에 세웠던 벽이 아니라면
				continue;
			}
			if(map[i][j] == 0){
				map[i][j] = 1; //벽세우기
				dfs(cnt+1, i, j);
				map[i][j] = 0; //원상복귀
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>N>>M;

	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++){
			cin>>map[i][j];
			if(map[i][j] == 2)
				v.push_back(make_pair(i, j));
		}
	v_size = v.size();

	dfs(0,0,-1);

	cout<<result<<"\n";

	return 0;
}