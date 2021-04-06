#include <iostream>
#include <vector>

using namespace std;

int N;
int map[101][101] = {0,};
int dy[4] = {0,-1,0,1};
int dx[4] = {1,0,-1,0};

int next_dir(int dir){
	int ndir;
	if(dir == 0)		ndir = 1;
	else if(dir == 1)	ndir = 2;
	else if(dir == 2)	ndir = 3;
	else if(dir == 3)	ndir = 0;
	return ndir;
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>N;
	for(int i=0; i<N; i++){
		int x,y,d,g;
		cin>>x>>y>>d>>g;
		
		vector<int> dir;

		dir.push_back(d);
		for(int k=0; k<g; k++){
			vector<int> temp = dir;
			
			int size = temp.size();
			for(int j=size-1; j>=0; j--){
				dir.push_back(next_dir(temp[j]));
			}
		}

		map[y][x] = 1;
		int size = dir.size();
		for(int k=0; k<size; k++){
			y += dy[dir[k]];
			x += dx[dir[k]];
			
			if((y<0) || (x<0) || (y>=101) || (x>=101))
				continue; 
			map[y][x] = 1;
		}
	}
	int cnt = 0;

	for(int i=0; i<101; i++){
		for(int j=0; j<101; j++){
			if(map[i][j] && map[i][j+1] && map[i+1][j] && map[i+1][j+1])
				cnt++;
		}
	}
	cout<<cnt<<"\n";
	
	return 0;
}