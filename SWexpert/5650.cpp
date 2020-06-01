#include <iostream>
#include <vector>
#include <math.h>

#define MAX 101
using namespace std;

int pin[MAX][MAX];
int n;


// yoongoing loveyou
//현재 볼의 위치
pair<int, int> ball;

typedef struct {
	int type;
	int y;
	int x;
}Hole;

vector<Hole> hole;


int ans = 0;

void init_(){
	for(int i=1; i<=101; i++)
		for(int j=1; j<=101; j++)
			pin[i][j] = 0;
	hole.clear();
}

//현재 방향의 반대방향 
int conv_dir(int dir){
	int conv;
	if(dir == 0)
		conv = 1;
	else if(dir == 1)
		conv = 0;
	else if(dir == 2)
		conv = 3;
	else if(dir == 3)
		conv = 2;

	return conv;
}


//도형의 수직면을 만날때
int next_dir(int num, int dir){
	int next;
	if(num == 5)						return conv_dir(dir); 
	
	if(dir == 0 && (num==3 || num==4))	next = conv_dir(dir);
	else if(dir == 0 && num == 1)		next = 2;
	else if(dir == 0 && num == 2)		next = 3;

	if(dir == 1 && (num==1 || num==2)) 	next = conv_dir(dir);
	else if(dir == 1 && num == 3)		next = 3;
	else if(dir == 1 && num == 4)		next = 2;

	if(dir == 2 && (num==1 || num==4))	next = conv_dir(dir);
	else if(dir == 2 && num == 2)		next = 1;
	else if(dir == 2 && num == 3)		next = 0;
	
	if(dir == 3 && (num==2 || num==3))	next = conv_dir(dir);
	else if(dir == 3 && num == 1)		next = 1;
	else if(dir == 3 && num == 4)		next = 0;

	return next;
}

void simulator(int score, int dir, int y, int x, int cnt){
	//초기자리로 돌아오면 stop 
	if((cnt!=0) && (y == ball.first) && (x == ball.second)){
		ans = max(ans,score);		
		return;
	}
	
	//블랙홀에 빠지면 stop
	else if(pin[y][x] == -1){
		ans = max(ans,score);
		return;
	}
	
		
	
	//웜홀이면 반대 웜홀좌표로 간다
	else if((pin[y][x]>=6) && (pin[y][x]<=10)){
		int size = hole.size();
		for(int i=0; i<size; i++){
			if((pin[y][x]==hole[i].type) && (y!=hole[i].y) && (x!=hole[i].x)){
				y = hole[i].y;
				x = hole[i].x;
				break;
			}
		}
		if(dir == 0) 		x-=1;
		else if(dir == 1)	x+=1;
		else if(dir == 2)	y-=1;
		else if(dir == 3)	y+=1;
		simulator(score,dir,y,x,cnt+1);
	}
	//도형을 만난다면
	else if(pin[y][x]>=1 && pin[y][x]<=5){
		int next = next_dir(pin[y][x],dir);
		if(next == 0)		simulator(score+1,next,y,x-1,cnt+1);
		else if(next == 1)	simulator(score+1,next,y,x+1,cnt+1);
		else if(next == 2)	simulator(score+1,next,y-1,x,cnt+1);
		else if(next == 3)	simulator(score+1,next,y+1,x,cnt+1);
	}

	//벽에 닿으면 반대방향
	else if(y == 0 || x == 0 || y == n+1 || x == n+1){
		int next = conv_dir(dir);

		if(next == 0)		simulator(score+1,next,y,x-1,cnt+1);
		else if(next == 1)	simulator(score+1,next,y,x+1,cnt+1);
		else if(next == 2)	simulator(score+1,next,y-1,x,cnt+1);
		else if(next == 3)	simulator(score+1,next,y+1,x,cnt+1);
	}

	//빈칸일 경우에는 계속 이동
	else if(dir == 0 && pin[y][x] == 0)
		simulator(score,dir,y,x-1,cnt+1);
		
	else if(dir == 1 && pin[y][x] == 0)
		simulator(score,dir,y,x+1,cnt+1);
	
	else if(dir == 2 && pin[y][x] == 0)
		simulator(score,dir,y-1,x,cnt+1);
	
	else if(dir == 3 && pin[y][x] == 0)
		simulator(score,dir,y+1,x,cnt+1);
	
}

void controller(){
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(pin[i][j] == 0){
				for(int k=0; k<4; k++){
					ball.first = i;
					ball.second = j;
					simulator(0,k,i,j,0);
				}
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	int test_case;
	cin>>test_case;

	for(int t=1; t<=test_case; t++){
		cin>>n;
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++){
				cin>>pin[i][j];
				if((pin[i][j]>=6) && (pin[i][j]<=10)){
					Hole h;
					h.type = pin[i][j];
					h.y = i;
					h.x = j;
					hole.push_back(h);
				}
			}
		
		controller();
		cout<<"#"<<t<<" "<<ans<<endl;
		ans = 0;
		init_();
	}
	return 0;
}