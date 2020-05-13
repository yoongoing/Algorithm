#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#define MAX 100
using namespace std;

int M,N;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int map[MAX+1][MAX+1] = {0,};
int check[MAX+1][MAX+1] = {0,};

string str;
void init_(){
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			check[i][j] = 987654321;
		}
	}
	check[1][1] = 0;
}

void bfs(int y, int x){
	queue<pair<int, int> > q;
	q.push(make_pair(y,x));
	
	check[y][x] = true;

	while(!q.empty()){
		y = q.front().first;
		x = q.front().second;
		q.pop();

		for(int i=0; i<4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];

			if(ny>N || nx>M || ny<1 || nx<1) 
				continue;

			if(check[ny][nx] > check[y][x] + map[ny][nx]){
				check[ny][nx] = check[y][x] + map[ny][nx];
				q.push(make_pair(ny,nx));
			}
		}
	}
}
	


int main(int argc, char const *argv[])
{
	cin>>M>>N;


	for(int i=1; i<=N; i++){
		cin>>str;
		for(int j=0; j<M; j++){
			map[i][j+1] = str[j] - 48;
		}
	}
	init_();
	bfs(1,1);

	cout<<check[N][M]-1<<endl;
	return 0;
}