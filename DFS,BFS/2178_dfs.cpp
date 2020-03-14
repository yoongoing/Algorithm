#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

int X,Y;
int map[100][100];
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
int min_;

void dfs(int y, int x, int sum){
	printf("(%d,%d)\n",y,x );
	
	if(y == Y-1 && x == X-1){
		min_ = min(min_, sum);
		return;
	}
	map[y][x] = 0;
	int ans = X*Y;
	for(int i=0; i<4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];

		if(ny<0 || nx<0 || (ny>Y-1) || (nx>X-1)) continue;

		if(map[ny][nx] == 1){
			map[ny][nx] = 0;
			dfs(ny,nx,sum+1);
			map[ny][nx] = 1;
		}
	}
}

int main(void)
{
	string str;
	cin>>Y>>X;

	min_ = Y*X;

	for(int i=0; i<Y; i++){
		cin>>str;
		for(int j=0; j<X; j++){
			map[i][j] = str.at(j) - 48;
		}
	}
	dfs(0,0,1);
	cout<<min_;

	return 0;
}