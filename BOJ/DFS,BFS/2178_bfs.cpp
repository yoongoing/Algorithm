#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <list>
#include <queue>

using namespace std;

int map[100][100];
int y_[4] = {-1,1,0,0};
int x_[4] = {0,0,1,-1};
int X,Y;

void BFS(int y, int x){
	queue<pair<int,int> > q;
	q.push(make_pair(y,x));

	while(!q.empty()){
		y = q.front().first;
		x = q.front().second;
		//printf("(%d, %d) value: %d\n",y,x,map[y][x]);
		q.pop();

		for(int i=0; i<4; i++){
			int ny = y + y_[i];
			int nx = x + x_[i];
			if(ny<0 || ny>Y-1 || nx<0 || nx>X-1) continue;
			if(map[ny][nx] == 1){
				q.push(make_pair(ny,nx));
				map[ny][nx] = map[y][x] + 1;
			}
			
		}
	}
	
}


int main(void)
{
	string str;
	cin>>Y>>X;

	for(int i=0; i<Y; i++){
		cin>>str;
		for(int j=0; j<X; j++){
			map[i][j] = str.at(j) - 48;
		}
	}
	map[0][0] = 2;
	
	BFS(0,0);
	cout<<(map[Y-1][X-1]-1);
	return 0;
}