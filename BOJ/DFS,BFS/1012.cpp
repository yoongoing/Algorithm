#include <cstring>
#include <iostream>

using namespace std;

int ground[51][51]={0,};
bool check[51][51] = {0,};
int T,M,N,K;
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};



void init()
{
	for(int i=0; i<51; i++)
		for(int j=0; j<51; j++)
		{
			ground[i][j] = 0;
			check[i][j] = 0;
		}
}
void dfs(int y, int x){
	check[y][x] = 1;
	
	for(int i=0; i<4; i++){
		int nx = x + dx[i], ny = y + dy[i];

		if(ny<0 || nx<0 || (ny>N-1) || (nx>M-1)) continue;
		
		if(ground[ny][nx] == 1 && !check[ny][nx]){
			dfs(ny,nx);
		}
	}
}


int main(int argc, char const *argv[])
{
	
	cin>>T;

	for(int t=0; t<T; t++){
		
		cin>>M>>N>>K;

		for (int i=0; i<K; i++){
			int X,Y;
			cin>>X>>Y;
			ground[Y][X] = 1;
		}

		int count = 0;

		for(int i=0; i<N; i++){
			for(int j=0; j<M; j++){
				if(ground[i][j] && !check[i][j]){
					dfs(i,j);
					count++;
				}
			}
		}

		cout<<count<<endl;
		init();	
	}	
	return 0;
}







