#include <iostream>
#include <algorithm>

#define MAX 30
using namespace std;

int cnt;
double result;
double prop[4];
bool check[MAX][MAX];

int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};

void dfs(int y ,int x,int probability){
	if(cnt == 0){
		result+= probability;
		return;
	}
	check[y][x] = true;

	for(int i=0; i<4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];

		if(!check[ny][nx]){
			N--;
			dfs(ny,nx,probability*prob[i]);
			N++;
			check[ny][nx] = false;
		}		
	}
}

int main(int argc, char const *argv[])
{
	cin>>cnt
	for(int i=0; i<4; i++){
		cin>>prop[i];
		prop[i] *= 0.01
	}
	
	dfs(n);
	return 0;
}