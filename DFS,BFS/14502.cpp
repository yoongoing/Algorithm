#include <iostream>
#include <queue>
#include <math.h>

#define MAX 9
using namespace std;

int n,m;
int map[MAX][MAX];
int cpy_map[MAX][MAX];
queue<pair<int, int> > virus;

int dy[4] = {0,0,-1,1};
int dx[4] = {1,-1,0,0};

int ans = 0;

bool check(int y, int x){
	if((y<1) || (x<1) || (y>n) || (x>m))
		return false;
	return true;
}

int count(int (*arr)[MAX]){
	int cnt = 0;

	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			if(arr[i][j] == 0)
				cnt++;
	return cnt;
}

//바이러스를 퍼트리는 함수
void bfs(){
	int curr[MAX][MAX];
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			curr[i][j] = cpy_map[i][j];


	queue<pair<int, int> > q;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			if(curr[i][j] == 2)
				q.push(make_pair(i,j));


	while(!q.empty()){
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for(int i=0; i<4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];

			if(!check(ny,nx))
				continue;

			if(curr[ny][nx] == 0){
				q.push(make_pair(ny,nx));
				curr[ny][nx] = 2;
			}
		}
	}

	ans = max(ans,count(curr));
}


//벽을 3개를 세워버리는 함수
void dfs(int cnt){
	if(cnt == 3){
		bfs();
		return;
	}

	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			if(cpy_map[i][j] == 0){
				cpy_map[i][j] = 1;
				dfs(cnt+1);
				cpy_map[i][j] = 0;
			}
}

int main(int argc, char const *argv[])
{
	cin>>n>>m;

	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			cin>>map[i][j];
		}
	}

	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(map[i][j] == 0){
				
				for (int k=1; k<=n; k++)
					for (int l=1; l<=m; l++)
						cpy_map[k][l] = map[k][l];

				cpy_map[i][j] = 1;
				dfs(1);
				cpy_map[i][j] = 0;
			}
		}
	}
	
	cout<<ans<<endl;
	return 0;
}