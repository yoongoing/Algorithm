#include <iostream>
#include <vector>

using namespace std;

typedef struct{
	int y;
	int x;
	int dir;
}S;


int total = 987654321;
int sum = 0;

int dy[8] = {-1,-1, 0, 1,1,1,0,-1};
int dx[8] = { 0,-1,-1,-1,0,1,1, 1};

vector<pair<int, int> >v[4][4];
vector<pair<int, int> >v2;
vector<S>shark;

// void fish_moving(){
// 	for(int i=0; i<4; i++){
// 		for(int j=0; j<4; j++){
// 			if((v[i][j].first == -1))
// 				continue;
// 			int ny = i + dy[v[i][j].second - 1];
// 			int nx = j + dx[v[i][j].second - 1];

// 			if(v[ny][nx].first == -1)
// 				v[i][j].second = (v[i][j].second+1) % 8;
// 				continue;
// 			if((ny<0) || (nx<0) || (ny>=4) || (nx>=4))
// 				v[i][j].second = (v[i][j].second+1) % 8;
// 				continue;

// 			int temp_num = v[ny][nx].first;
// 			int temp_dir = v[ny][nx].second;

// 			v[ny][nx].first = v[i][j].first;
// 			v[ny][nx].second = v[i][j].second;
// 			v[i][j] = temp_num;
// 			v[i][j] = temp_dir;
// 		}
// 	}
// }

// void dfs(int y, int x){
// 	int shark_dir = v[i][j].second;
// 	v[i][j].second = 0;
	
// 	fish_moving();
	
// 	vector<pair<int, int> >possible_dir;
// 	while(1){
// 		int ny = y + dy[shark_dir-1];
// 		int nx = x + dx[shark_dir-1];

// 		if((ny<0) || (nx<0) || (ny>3) || (nx>3))
// 			break;
// 		possible_dir.push_back(make_pair(ny,nx));
// 	}
// 	int size = possible_dir.size();

// 	if(size == 0){
// 		total = min(total, sum);
// 		return;
// 	}

// 	for(int i=0; i<size; i++){
// 		sum += possible_dir[i].first;
// 		dfs(possible_dir[i].first, possible_dir[j]);
// 		sum -= possible_dir[i].first;
// 	}
// }

int main(int argc, char const *argv[])
{
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			int num, dir;
			v[i][j].push_back(make_pair(num,dir));
			if(i==0 && j==0)
				continue;
			v2.push_back(make_pair(num,dir));
		}
	}
	sort(v2.begin(), v2.end());
	for(int i=0; i<v2.size(); i++){
		cout<<v2[i].first<<" "<<v2[i].second<<"\n";
	}
	sum += v[0][0][0];
	v[0][0][0] = -1;
	// dfs(0, 0);

	return 0;
}