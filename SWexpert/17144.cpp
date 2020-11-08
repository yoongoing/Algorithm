#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int R,C,T;
int map[51][51];
int dy[4] = {0,0,-1,1};
int dx[4] = {-1,1,0,0};

vector<pair<int,int> > v[2];

typedef struct{
	int y;
	int x;
	int s;
}D;

void w(){
	// 공기청정기 작동
	for(int k=0; k<2; k++){
		int y = v[k][0].first;
		int x = v[k][0].second;

		int temp = 0;
		for(int i=1; i<v[k].size(); i++){
			int ny = v[k][i].first;
			int nx = v[k][i].second;

			int next = map[ny][nx];

			if(next == -1){
				continue;
			}
			map[ny][nx] = temp;
			temp = next;
		}
	}
}


void s(){
	queue<D> q;

	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			if(map[i][j] > 4){
				D dust;
				dust.y = i;
				dust.x = j;
				dust.s = map[i][j];
				q.push(dust);
			}
		}
	}

	//T초만큼
	while(!q.empty()){
		int y = q.front().y;
		int x = q.front().x;
		int s = q.front().s;
		q.pop();
		
		int cnt = 0;

		for(int k=0; k<4; k++){
			int ny = y + dy[k];
			int nx = x + dx[k];

			if((ny<0) || (nx<0) || (ny>=R) || (nx>=C) || (map[ny][nx]==-1))
				continue;

			map[ny][nx] += s / 5;
			cnt++;
		}
		map[y][x] -= ((s/5) * cnt);
	}						
}

int sol(){
	for(int k=0; k<T; k++){
		s();
		w();
	}
	int sum = 0;
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			if((map[i][j]!=-1) && (map[i][j]!=0))
				sum += map[i][j];
		}
	}
	return sum;
	
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>R>>C>>T;
	int cnt = 0;
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			cin>>map[i][j];
			if(map[i][j] == -1){
				if(cnt == 0){
					int y = i;
					int x = j;

					for(; x<C; x++)
						v[cnt].push_back(make_pair(y,x));
					x -= 1;
					y -= 1;
					for(; y>=0; y--)
						v[cnt].push_back(make_pair(y,x));
					y += 1;
					x -= 1;
					for(; x>=j; x--)
						v[cnt].push_back(make_pair(y,x));
					x += 1;
					y += 1;
					for(; y<=i; y++)
						v[cnt].push_back(make_pair(y,x));
					cnt++;
				}
				
				else{
					int y = i;
					int x = j;

					for(; x<C; x++)
						v[cnt].push_back(make_pair(y,x));
					x -= 1;
					y += 1;
					for(; y<R; y++)
						v[cnt].push_back(make_pair(y,x));
					y -= 1;
					x -= 1;
					for(; x>=j; x--)
						v[cnt].push_back(make_pair(y,x));
					x += 1;
					y -= 1;
					for(; y>=i; y--)
						v[cnt].push_back(make_pair(y,x));
				}
			}
		}
	}
	// w();

	cout<<sol()<<"\n";
	
	return 0;
}
