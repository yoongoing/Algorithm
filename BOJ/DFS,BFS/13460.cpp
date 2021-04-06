#include <iostream>
#include <string.h>
#include <queue>
#include <math.h>

#define MAX 11
using namespace std;

int N,M;		//N은 세로, M은 가로

int R_y, R_x;	//R		위치
int B_y, B_x;	//B		위치
int H_y, H_x;	//Hole	위치

char board[MAX][MAX];

int ans = 987654321;

bool R,B;

//전에 움직인 방향의 반대방향을 알려주는 함수
int conv_dir(int dir){
	int conv;
	if(dir == -1)		conv = -1;
	
	if(dir == 0)		conv =  1; 		
	else if(dir == 1) 	conv =  0;
	else if(dir == 2)	conv =  3;
	else if(dir == 3)	conv =  2;

	return conv;
}



//공의 좌표가 같을때, 전에 기울인 방향에 따라 공의 좌표를 재설정 해주는 함수
int remark(int dir){
	int prior;
	if(dir == 0){
		if(R_x < B_x)	prior = 0;
		else			prior = 1;
	}

	else if(dir == 1){
		if(R_x > B_x)	prior = 0;
		else			prior = 1;	
	}

	else if(dir == 2){
		if(R_y < B_y)	prior = 0;
		else			prior = 1;
	}

	else if(dir == 3){
		if(R_y > B_y)	prior = 0;
		else			prior = 1;
	}

	return prior;
}



//빨간공과 파란공의 좌표가 같을시 재업댓
void move(int prior, int dir){
	switch(dir){
		case 0:
			if(prior == 0)		B_x += 1;
			else				R_x += 1;
			break;

		case 1:
			if(prior == 0)		B_x -= 1;
			else				R_x -= 1;
			break;

		case 2:
			if(prior == 0)		B_y += 1;
			else				R_y += 1;
			break;

		case 3:
			if(prior == 0)		B_y -= 1;
			else				R_y -= 1;
			break;
	}
}

int moveRow(int y, int x, int dir){
    int next = y;

    if (dir == 2){
        for (int row=y-1; row > 0; row--){
            if (board[row][x] == '#')
                break;
            else if (board[row][x] == 'O'){
                next = row;
                break;
            }
            else
                next = row;
        }
    }

    else if (dir == 3){
        for (int row=y+1; row < N-1; row++){
            if (board[row][x] == '#')
                break;
            else if (board[row][x] == 'O'){
                next = row;
                break;
            }
            else
                next = row;
        }
    }
    return next;
}

int moveCol(int y,int x,int dir){
    int next = x;

    if (dir == 0){
        for (int col=x-1; col>0; col--){
            if (board[y][col] == '#')
                break;
            else if (board[y][col] == 'O'){
                next = col;
                break;
            }
            else
                next = col;
        }
    }

    else if (dir == 1){
        for (int col=x+1; col<M-1; col++){
            if (board[y][col] == '#')
                break;
            else if (board[y][col] == 'O'){
                next = col;
                break;
            }
            else
                next = col;
        }
    }
    return next;
}

//0:왼쪽, 1:오른쪽, 2:위, 3:아래
void shift(int dir){
    if (dir == 2 || dir == 3){
        R_y = moveRow(R_y, R_x, dir);
        B_y = moveRow(B_y, B_x, dir);
    }
    else if (dir == 0 || dir == 1){
        R_x = moveCol(R_y, R_x, dir);
        B_x = moveCol(B_y, B_x, dir);
    }
}

void check(){
	if(R_y == H_y && R_x == H_x)
		R = true;
	if(B_y == H_y && B_x == H_x)
		B = true;
}

void dfs(int cnt, int prev_dir){
	//cnt가 10을 초과했는데, 찾지 못했다 => 실패!
	if(cnt > 10){
		R = false;
		B = false;
		return;
	}
	//파란공이 구멍에 빠졌다 => 실패!
	if(B){
		R = false;
		B = false;
		return;
	}
	//빨간공이 구멍에 빠졌다 => ans와 cnt중 작은값으로 업뎃
	if(R){
		R = false;
		B = false;
		ans = min(ans,cnt);
		return;
	}
	



	//현재 빨간공과 파란공의 좌표
	int red_y = R_y, red_x = R_x;
	int blue_y = B_y, blue_x = B_x;



	for(int i=0; i<4; i++){
		//이전에 했던 방향은 해도 같을 것이며, 반대 방향으로 하면 원점으로 돌아옴
		if(prev_dir == i || conv_dir(i) == i)
			continue;
		


		//만약 빨간공 파란공의 위치가 같을 때, 방향에 좌표 재설정을 위해 우선순위 확인
		int prior = remark(i);



		//움직여 보자!
		shift(i);
		check();

		

		//shift하고 난 후의 빨간공과 파란공의 위치가 같다면, 우선순위에 따라 좌표 재설정
		if(R_y == B_y  &&  R_x == B_x)
			move(prior,i);
		
		//다음 움직임을 위해 dfs호출
		dfs(cnt+1,i);



		R_y = red_y,	R_x = red_x;
		B_y = blue_y,	B_x = blue_x;
	}
}

int main(int argc, char const *argv[])
{
	cin>>N>>M;
	
	

	for(int i=0; i<N; i++){
		string str;
		cin>>str;
		for(int j=0; j<M; j++){
			if(str[j] == 'R'){
				R_y = i;
				R_x = j;
			}
			else if(str[j] == 'B'){
				B_y = i;
				B_x = j;
			}
			else if(str[j] == 'O'){
				H_y = i;
				H_x = j;
			}
			board[i][j] = str[j];
		}
	}

	dfs(0,-1);

	if(ans == 987654321)
		cout<<"-1"<<endl;
	else
		cout<<ans<<endl;

	return 0;
}