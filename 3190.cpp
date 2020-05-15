#include <iostream>
#include <deque>
#include <vector>
#include <queue>

#define MAX 101
using namespace std;

int n,k,l;
int board[MAX][MAX];
bool flag;
int ans=0;
deque<pair<int, int> > snake;
queue<pair<int, char> > q;

//이전 방향에 따라 다음에 가야할 방향을 리턴해주는 함수
int next(int prev_dir, char c){
	int next;
	if(prev_dir == -1)					next = 1;
	
	if(prev_dir == 0 && c == 'D') 		next = 2;
	else if(prev_dir == 0 && c == 'L') 	next = 3;
	
	if(prev_dir == 1 && c == 'D') 		next = 3;
	else if(prev_dir == 1 && c == 'L') 	next = 2;
	
	if(prev_dir == 2 && c == 'D') 		next = 1;
	else if(prev_dir == 2 && c == 'L') 	next = 0;

	if(prev_dir == 3 && c == 'D') 		next = 0;
	else if(prev_dir == 3 && c == 'L') 	next = 1;

	return next;
}

//뱀의 위치를 업데이트 시켜주는 함수
void check_position(int y, int x){
	int size = snake.size();

	if( (y<1) || (x<1) || (y>n) || (x>n) ){
		flag = true;
		return;
	}
	for(int i=1; i<size; i++){
		if(y == snake[i].first && x == snake[i].second){
			flag = true;
			return;
		}
			
	}
}

int sol(int cnt, int y, int x, int prev_dir){
	int time 		= q.front().first;
	char dir 		= q.front().second;
	int next_dir 	= next(prev_dir,dir);
	prev_dir = next_dir;
	q.pop();

	while(true){
		if(cnt == time){
			time = q.front().first;
			next_dir = next(prev_dir,dir);
			dir = q.front().second;
			prev_dir = next_dir;
			if(!q.empty())
				q.pop();
		}

		if(next_dir == 0){
			x -= 1;
		}
		else if(next_dir == 1){
			x += 1;
		}
		else if(next_dir == 2){
			y -= 1;
		}
		else if(next_dir == 3){
			y += 1;
		}
		
		check_position(y,x);

		if(!flag){
			snake.push_front(make_pair(y,x));
			if(board[y][x] != 3){
				snake.pop_back();
			}
			else
				board[y][x] = 0;
		}
		else	
			return cnt;
		cnt++;
	}
}


int main(int argc, char const *argv[])
{
	cin>>n>>k;
	for(int i=0; i<k; i++){
		int idx_y,idx_x;
		cin>>idx_y>>idx_x;
		board[idx_y][idx_x] = 3;
	}
	
	cin>>l;
	for(int i=0; i<l; i++){
		int step;
		char d;
		cin>>step>>d;
		q.push(make_pair(step,d));
	}

	snake.push_front(make_pair(1,1));

	//0:왼쪽 1:오른쪽 2:위 3:아래
	//cnt,y,x,prev_dir
	ans = sol(0,1,1,-1);
	cout<<ans+1<<endl;

	return 0;
}