#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int R,C,M;
int map[102][102];

int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,1,-1};

typedef struct{
	int y;
	int x;
	int speed;
	int dir;
	int size;
}S;

vector<S> v;

int shark_sum = 0;

int v_dir(int dir){
	if(dir == 1)
		return 2;
	if(dir == 2)
		return 1;
	if(dir == 3)
		return 4;
	if(dir == 4)
		return 3;
	return -1;
}

void grasp(int x){
	vector<S> temp_v;
	int s_i = -1;

	for(int i=1; i<=R; i++){
		if(map[i][x] != 0){
			s_i = i;
			shark_sum += map[i][x];
			map[i][x] = 0;
			break;
		}
	}
	if(s_i == -1)
		return;

	for(int i=0; i<v.size(); i++){
		if((v[i].y==s_i) && (v[i].x==x))
			continue;
		temp_v.push_back(v[i]);
	}
	v.clear();
	v = temp_v;
}

void move(){
	queue<S> q;
	vector<S> temp_v;
	
	int cmap[101][101] = {0,};

	for(int k=0; k<v.size(); k++)
		q.push(v[k]);

	while(!q.empty()){
		int y = q.front().y;
		int x = q.front().x;
		int speed = q.front().speed;
		int dir = q.front().dir;
		int size = q.front().size;
		q.pop();

		if((y==1) && dir == 1)
			dir = v_dir(dir);
		else if((x==1) && dir == 4)
			dir = v_dir(dir);
		else if((y==R) && dir == 2)
			dir = v_dir(dir);
		else if((x==C) && dir == 3)
			dir = v_dir(dir);

		for(int i=0; i<speed; i++){
			y += dy[dir-1];
			x += dx[dir-1];

			if((y==1) && dir == 1)
				dir = v_dir(dir);
			else if((x==1) && dir == 4)
				dir = v_dir(dir);
			else if((y==R) && dir == 2)
				dir = v_dir(dir);
			else if((x==C) && dir == 3)
				dir = v_dir(dir);
		}

		if(cmap[y][x] == 0){
			cmap[y][x] = size; 
			S shark;
			shark.y = y;
			shark.x = x;
			shark.speed = speed;
			shark.dir = dir;
			shark.size = size;
			temp_v.push_back(shark);
		}
		
		else{
			if(cmap[y][x] < size){
				cmap[y][x] = size;
				S shark;
				shark.y = y;
				shark.x = x;
				shark.speed = speed;
				shark.dir = dir;
				shark.size = size;
				temp_v.push_back(shark);
			}	
		}
	}
	v.clear();
	v = temp_v;
	
	for(int i=1; i<=R; i++){
		for(int j=1; j<=C; j++){
			map[i][j] = cmap[i][j];
		}
	}
}

void sol(){
	for(int i=1; i<=C; i++){
		grasp(i);
		move();
	}
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>R>>C>>M;

	for(int i=0; i<M; i++){
		S shark;
		cin>>shark.y>>shark.x>>shark.speed>>shark.dir>>shark.size;
		map[shark.y][shark.x] = shark.size;
		
		v.push_back(shark);
	}

	sol();

	cout<<shark_sum<<"\n";
	return 0;
}