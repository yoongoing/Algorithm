#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int N,M;
int map[51][51] = {0,};
vector<pair<int, int> > virus;
int check[11] = {0,};

int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

int min_sec = 987654321;
int Empty = 0;

int go(){
	queue<pair<int,int> > q;
	int sec[51][51];
	memset(sec, -1, sizeof(sec));
	
	int size = virus.size();
	for(int k=0; k<size; k++){
		if(check[k]){
			q.push(make_pair(virus[k].first, virus[k].second));
			sec[virus[k].first][virus[k].second] = 0;
		}
	}

	int infect = 0;
	int total_time = 0;

	while(!q.empty()){
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		
		for(int i=0; i<4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];

			if((ny<0) || (nx<0) || (ny>=N) || (nx>=N))
				continue;
			
			if((map[ny][nx] == 0) && sec[ny][nx]==-1){
				sec[ny][nx] = sec[y][x] + 1;
				q.push(make_pair(ny, nx));
				infect++;
				total_time = sec[ny][nx];
			}

			if((map[ny][nx] == 2) && sec[ny][nx]==-1){
				sec[ny][nx] = sec[y][x] + 1;
				q.push(make_pair(ny, nx));
			}
		}
	}

	if(Empty == infect)
		return total_time;

	return min_sec;
}

void dfs(int idx, int cnt){
	if(cnt == M){
		int sec = go();
		min_sec = min(min_sec, sec);
		return;
	}
	int size = virus.size();
	for(int i=idx+1; i<size; i++){
		check[i] = 1;
		dfs(i, cnt+1);
		check[i] = 0;
	}

}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>N>>M;

	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin>>map[i][j];
			if(map[i][j] == 0)
				Empty++;
			if(map[i][j] == 2)
				virus.push_back(make_pair(i, j));

		}
	}

	dfs(-1, 0);
	if(min_sec == 987654321)
		cout<<"-1\n";
	else
		cout<<min_sec<<"\n";
	return 0;
}