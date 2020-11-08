#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int N;
int map[21][21];
int visited[21][21];

int area[5];

int answer;

void select(int x, int y, int d1, int d2){
	int i,j;
	memset(visited,0,sizeof(visited));
	memset(area,0,sizeof(area));
	
	// 5번 경계선 
	for(i=0; i<=d1; i++){
		visited[x+i][y-i] = 1;
		visited[x+i+d2][y-i+d2] = 1;
		area[4] += map[x+i][y-i] + map[x+i+d2][y-i+d2];
	}
	for(i=1; i<d2; i++){
		visited[x+i][y+i] = 1;
		visited[x+i+d1][y+i-d1] = 1;
		area[4] += map[x+i][y+i] + map[x+i+d1][y+i-d1];
	}

	// 5번 경계선 내부 
	for(i=0; i<d1; i++){
		j=0;
		while(!visited[x+i+j+1][y-i]){
			visited[x+i+j+1][y-i] = 1;
			area[4] += map[x+i+j+1][y-i];
			j++;
		}
	}
	for(i=1; i<d2; i++){
		j=0;
		while(!visited[x+i+j+1][y+i]){
			visited[x+i+j+1][y+i] = 1;
			area[4] += map[x+i+j+1][y+i];
			j++;
		}
	}

	// 1~4 선거구 선택
	for(i=1; i<=N; i++){
		for(j=1; j<=N; j++){
			if(visited[i][j])
				continue;
			if((i<x+d1) && (j<=y))				area[0] += map[i][j];
			else if((i<=x+d2) && (y<j))			area[1] += map[i][j];
			else if((x+d1<=i) && (j<y-d1+d2))	area[2] += map[i][j];
			else if((x+d2<i) && (y-d1+d2<=j))	area[3] += map[i][j];
		}
	}

	sort(area, area+5);
	answer = min(answer, abs(area[0] - area[4]));
}

void devide(){
	for(int x=1; x<=N-2; x++){ //x
		for(int y=2; y<=N-1; y++){ //y
			int d1 = 1;
			int d2 = 1;
			
			while(1){
				if((x+d1+d2<=N) && (1<=y-d1) && (y+d2<=N)){
					select(x,y,d1,d2++);
				}
				else{
					d2 = 1;
					if(!((x+d1+d2<=N) && (1<=y-d1) && (y+d2<=N))){
						break;
					}
					d1++;
				}
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>N;

	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			cin>>map[i][j];
		}
	}
	answer = 987654321;
	devide();
	cout<<answer<<"\n";
	return 0;
}