#include <iostream>
#include <math.h>

#define MAX 501
using namespace std;

int n,m;
int paper[MAX][MAX];

int ans = 0;

int dy[4] = {0,0,-1,1};
int dx[4] = {1,-1,0,0};

bool check(int y, int x){
	if((y<0) || (x<0) || (y>=n) || (x>=m))
		return false;
	return true;
}


int conv_dir(int prev){
	int conv;

	if(prev == 0) conv = 1;
	else if(prev == 1) conv = 0;
	else if(prev == 2) conv = 3;
	else if(prev == 3) conv = 2;

	return conv;
}


void another_techromino(int y, int x){
	//ㅓ : y+1 y-1 x+1
	if((y+1<n) && (y-1>=0) && (x+1<m))
		ans = max(ans, paper[y][x]+paper[y+1][x+1]+paper[y-1][x+1]+paper[y][x+1]);
	
	//ㅗ : y+1 x+1 x-1
	if((y+1<n) && (x+1<m) && (x-1>=0))
		ans = max(ans, paper[y][x]+paper[y+1][x+1]+paper[y+1][x-1]+paper[y+1][x]);
	
	//ㅏ : y+1 y-1 x-1
	if((y+1<n) && (y-1>=0) && (x-1>=0))
		ans = max(ans, paper[y][x]+paper[y+1][x-1]+paper[y-1][x-1]+paper[y][x-1]);
	
	//ㅜ : y-1 x+1 x-1
	if((y-1>=0) && (x+1<m) && (x-1>=0))
		ans = max(ans, paper[y][x]+paper[y-1][x+1]+paper[y-1][x-1]+paper[y-1][x]);
}


void dfs(int cnt, int y, int x, int total, int prev){
	total += paper[y][x];

	if(cnt == 4){
		ans = max(ans,total);
		return;
	}

	for(int i=0; i<4; i++){
		//다음 좌표 확인
		if(i == conv_dir(prev))
			continue;

		int ny = y + dy[i];
		int nx = x + dx[i];

		//다음 좌표가 범위안에 없다면 다음좌표로 고고
		if(!check(ny,nx))
			continue;

		//범위안에 있다면 dfs고고
		dfs(cnt+1, ny, nx, total, i);
	}
}

int main(int argc, char const *argv[])
{
	cin>>n>>m;

	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			cin>>paper[i][j];

	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++){
			dfs(1,i,j,0,-1);
			another_techromino(i,j);
		}
		
	cout<<ans<<endl;

	return 0;
}