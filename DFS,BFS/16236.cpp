#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int N;
int map[21][21], chk[21][21];

pair<int, int> shark;
int S_size = 2;
int cnt = 0;

int dy[4] = {0,0,-1,1};
int dx[4] = {-1,1,0,0};


int max_ = 21;
int max_dist = 402;
int min_dist, min_y, min_x;

// bool cmp(const fish & a, const fish & b)
// {
//     if (a.distance < b.distance) return true; // 제일 먼저 f를 기준으로 오름차순 정렬
//     else if (a.distance == b.distance) // 만약에 f가 같다면
//     {
//         if (a.y < b.y) return true; // t를 기준으로 오름차순 정렬
//         else if (a.y == b.y) // 만약에 t가 같다면
//         {
//             if (a.x < b.x) return true; // c를 기준으로 오름차순 정렬
//         }
//     }
//     // 각 경우에 대하여 else를 고려할 필요가 없다.
//     return false;
// }




void bfs(int y, int x){
	queue<pair<int, int> > q;
	
	q.push(make_pair(y,x));
	chk[y][x] = 0;

	while(!q.empty()){
		y = q.front().first;
		x = q.front().second;
		q.pop();

		for(int i=0; i<4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			if((y<0) || (x<0) || (y>=N) || (x>=N))
				continue;
			if((chk[ny][nx]!=-1) || (map[ny][nx]>S_size))
				continue;

			chk[ny][nx] = chk[y][x] + 1;
			
			if((map[ny][nx]!=0) && (map[ny][nx]<S_size)){ // 먹을수 있는 물고기라면
				if(min_dist > chk[ny][nx]){
					min_dist = chk[ny][nx];
					min_y = ny;
					min_x = nx;
				}
				else if(min_dist == chk[ny][nx]){
					if(min_y == ny){
                        if(min_x > nx){
                            min_y = ny;
                            min_x = nx;
                        }
                    }else if(min_y > ny){
                        min_y = ny;
                        min_x = nx;
                    }
				}
			}
			q.push(make_pair(ny,nx)); //이동도 하고
		}
	}
}
int sol(int sec, int N){
	while(1){
		memset(chk, -1, sizeof(chk));
		min_dist = max_dist;
		min_y = max_;
		min_x = max_;

		bfs(shark.first, shark.second);

		if(min_y != max_ && min_x != max_){
			sec += chk[min_y][min_x];
			cnt++;
			if(S_size == cnt){
				S_size += 1;
				cnt = 0;
			}
			
			map[min_y][min_x] = 0;
			
			shark.first = min_y;
			shark.second = min_x;
			
		}
		else
			break;
	}
	return sec;
}
int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>N;
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++){
			cin>>map[i][j];
			if(map[i][j] == 9){
				shark.first = i;
				shark.second = j;
				map[i][j] = 0;
			}
		}

	int sec = sol(0, N);
	cout<<sec<<endl;

	return 0;
}










