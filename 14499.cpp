#include <iostream>

#define MAX 21
using namespace std;

int n,m,Y,X,k;
int map[MAX][MAX];
int dir[1001];
int dise[6] = {0,0,0,0,0,0};

bool check(int y, int x){
	if( (y<0) || (x<0) || (y>=n) || (x>=m) )
		return false;
	return true;
}

void dise_update(int dir){
	//동: 오른쪽
	if(dir == 1){
		int temp3 = dise[3];
		int temp5 = dise[5];
		dise[3] = dise[1];
		dise[5] = dise[0];
		dise[0] = temp3;
		dise[1] = temp5;
	}
	//서: 왼쪽
	else if(dir == 2){
		int temp3 = dise[3];
		int temp5 = dise[5];
		dise[3] = dise[0];
		dise[5] = dise[1];
		dise[0] = temp5;
		dise[1] = temp3;
	}	
	//북: 위쪽
	else if(dir == 3){
		int temp2 = dise[2];
		int temp3 = dise[3];
		int temp4 = dise[4];
		int temp5 = dise[5];
		dise[5] = temp4;
		dise[4] = temp3;
		dise[3] = temp2;
		dise[2] = temp5;
	}
	//남: 아래쪽
	else if(dir == 4){
		int temp2 = dise[2];
		int temp3 = dise[3];
		int temp4 = dise[4];
		int temp5 = dise[5];
		dise[2] = temp3;
		dise[3] = temp4;
		dise[4] = temp5;
		dise[5] = temp2;
	}
}

void sol(int y, int x){
	
	for(int i=0; i<k; i++){
		int dy = y;
		int dx = x;
		int dirr = dir[i];

		//방향에 따른 좌표 업데이트
		if(dirr == 1){
			dx = x+1;
		}
		else if(dirr == 2){
			dx = x-1;
		}
		else if(dirr == 3){
			dy = y-1;
		}
		else if(dirr == 4){
			dy = y+1;
		}
		//좌표가 범위를 벗어났다면 명령 무시
		if(!check(dy, dx)) 
			continue;

		x = dx;
		y = dy;
		//좌표가 범위 안이라면 주사위 굴려주기
		dise_update(dirr);
		

		//굴리고나서 주사위랑 지도에 적힌 숫자 업뎃
		if(map[dy][dx] == 0)
			map[dy][dx] = dise[3];
		else{
			dise[3] = map[dy][dx];
			map[dy][dx] = 0;
		}

		cout<<dise[5]<<endl;
	}
}

int main(int argc, char const *argv[])
{
	cin>>n>>m>>Y>>X>>k;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			cin>>map[i][j];

	for(int i=0; i<k; i++)
		cin>>dir[i];

	sol(Y,X);
	return 0;
}