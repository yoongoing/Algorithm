#include <iostream>
#include <vector>

using namespace std;

typedef struct 
{
	int y;
	int x;
	int dir;
}C;

int N,K;

int map[13][13];
C horse[11];
vector<int> info[13][13];

int dy[5] = {0,0,0,-1,1};
int dx[5] = {0,1,-1,0,0};

int reverse_dir(int dir){
	int result;
	
	if(dir == 1)		result = 2;
	else if(dir == 2) 	result = 1;
	else if(dir == 3) 	result = 4;
	else if(dir == 4) 	result = 3;

	return result;
}

int find(int y, int x, int idx){
	for(int i=0; i<info[y][x].size(); i++)
		if(info[y][x][i] == idx)
			return i;
}

void move(int y, int x, int ny, int nx, int idx, int pos, int c){
	if(c == 0){
		for(int i=pos; i<info[y][x].size(); i++){
			info[ny][nx].push_back(info[y][x][i]);
			horse[info[y][x][i]].y = ny;
			horse[info[y][x][i]].x = nx;
		}
		for(int i=info[y][x].size()-1; i>=pos; i--){
			info[y][x].pop_back();
		}
	}
	else if(c == 1){
		for(int i=info[y][x].size()-1; i>=pos; i--){
			info[ny][nx].push_back(info[y][x][i]);
			horse[info[y][x][i]].y = ny;
			horse[info[y][x][i]].x = nx;
		}

		for(int i=info[y][x].size()-1; i>=pos; i--){
			info[y][x].pop_back();
		}

	}
	else if(c == 2){
		int dir = reverse_dir(horse[idx].dir);
		horse[idx].dir = dir;
		ny = y + dy[dir];
		nx = x + dx[dir];

		if((ny>=1) && (nx>=1) && (ny<=N) && (nx<=N)){
			if(map[ny][nx] != 2)
				move(y,x,ny,nx,idx,pos,map[ny][nx]);
		}
	}
}

int check(){
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			if(info[i][j].size() >= 4)
				return 1;
		}
	}
	return 0;
}

int sol(){
	int f = 0;
	int round, i, cnt;
	for(round=1; round<=1000; round++){
		for(i=0; i<K; i++){
			int y = horse[i].y;
			int x = horse[i].x;
			int dir = horse[i].dir;

			int ny = y + dy[dir];
			int nx = x + dx[dir];

			int pos = find(y,x,i);

			if((ny>=1) && (nx>=1) && (ny<=N) && (nx<=N)){
				move(y,x,ny,nx,i,pos,map[ny][nx]);
			}
			else{
				move(y,x,ny,nx,i,pos,2);
			}
			if(check()){
				f = 1;
				break;
			}
		}	
		if(f == 1)
			return round;
	}
	return -1;
}




int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>N>>K;

	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			cin>>map[i][j];
		}
	}

	for(int i=0; i<K; i++){
		C c;
		cin>>c.y>>c.x>>c.dir;
		horse[i] = c;
		info[c.y][c.x].push_back(i);
	}

	int ans = sol();
	cout<<ans<<"\n";
	return 0;
}