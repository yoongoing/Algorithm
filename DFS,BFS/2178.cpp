#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <list>


using namespace std;

int map[100][100]; 	// 말 그대로 지도 
int X,Y;			// N * M
int mini = 0;		// 최소거리를 출력해보자

void DFS(int y, int x, int sum){
	//printf("(%d,%d) sum:%d\n",y,x,sum);

	if(y == Y-1 && x == X-1){
		if(mini > sum) mini = sum;
		return;
	}

	map[y][x] = 0;

	if((y>0) 	&& map[y-1][x]) {DFS(y-1, x, sum+1);}
	if((y<Y-1) 	&& map[y+1][x])	{DFS(y+1, x, sum+1);}
	if((x>0) 	&& map[y][x-1]) {DFS(y, x-1, sum+1);}
	if((x<X-1) 	&& map[y][x+1]) {DFS(y, x+1, sum+1);}

	
	map[y][x] = 1;
}
void BFS(int y, int x, int sum){
	printf("(%d,%d) sum:%d\n",y,x,sum);

	if(y == Y-1 && x == X-1){
		if(mini > sum) mini = sum;
		return;
	}

	map[y][x] = 0;

	if((x>0) 	&& map[y][x-1]) {BFS(y, x-1, sum+1);}
	if((x<X-1) 	&& map[y][x+1]) {BFS(y, x+1, sum+1);}
	if((y>0) 	&& map[y-1][x]) {BFS(y-1, x, sum+1);}
	if((y<Y-1) 	&& map[y+1][x])	{BFS(y+1, x, sum+1);}
	
	map[y][x] = 1;
}



