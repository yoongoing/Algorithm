#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int n,m,k;
int map[301][301] = {0,};
bool chk[301][301] = {0,};
typedef struct 
{
	int y;
	int x;
	int life_time;
	int curr_time;
}Cell;

deque<Cell> dq;

int dy[4] = {0,0,-1,1};
int dx[4] = {-1,1,0,0};



int cmp(Cell A, Cell B)
{
    return A.life_time > B.life_time;
}

void init_(){
	for(int i=0; i<301; i++)
		for(int j=0; j<301; j++){
			map[i][j] = 0;
			chk[i][j] = false;
		}
}

void print(deque<Cell>qq){
	while(!qq.empty()){
		cout<<qq.front().y<<", "<<qq.front().x<<": "<<qq.front().life_time<<" "<<qq.front().curr_time<<endl;
		qq.pop_front();
	}
	cout<<endl<<endl;

}

void bfs(int y, int x, int time){
	
	for(int k=0; k<time; k++){
		int size = dq.size();

		for(int i=0; i<size; i++){
			y = dq.front().y;  //좌표 y
			x = dq.front().x;	//좌표 x
			int lt = dq.front().life_time;	//세포의 우선순위
			int ct = dq.front().curr_time;	//세포의 남은 시간
			dq.pop_front();
			
			if(ct > 1){
				Cell temp;
				temp.y = y;
				temp.x = x;
				temp.life_time = lt;
				temp.curr_time = ct - 1;
				dq.push_back(temp);
			}
			else if(ct == 1){
				chk[y][x] = true;

				for(int j=0; j<4; j++){
					int ny = y + dy[j];
					int nx = x + dx[j];

					if(!chk[ny][nx]){
						chk[ny][nx] = true;

						Cell temp;
						temp.y = ny;
						temp.x = nx;
						temp.life_time = lt;
						temp.curr_time = lt;

						dq.push_back(temp);
					}
				}
			}
		}
		sort(dq.begin(), dq.end(), cmp);  
		print(dq);
	}
}


int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	for(int testcase=1; testcase<=t; testcase++){
		cin>>n>>m>>k;
		int N = 300/n;
		int M = 300/m; 
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++){
				cin>>map[N+i][M+j];
				if(map[N+i][M+j] != 0){
					chk[N+i][M+j] = true;

					Cell temp;
					temp.y = N+i;
					temp.x = M+j;
					temp.life_time = map[N+i][M+j]*2;
					temp.curr_time = map[N+i][M+j]*2;
					dq.push_back(temp);
				}
			}
		bfs(N,M,k);

		cout<<dq.size()<<endl;
		dq.clear();
		init_();
	}
	
	return 0;
}