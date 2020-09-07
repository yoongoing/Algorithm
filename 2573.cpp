#include <iostream>
#include <queue>

using namespace std;

int N,M;
int map[301][301] = {0,};

int dy[4] = { 0,0,-1,1};
int dx[4] = {-1,1, 0,0};


bool seacheck(int y, int x){
	// 범위를 벗어나면
	if((y<0) || (x<0) || (y>=N) || (x>=M))
		return true;
	// 해수가 아니라면
	if(map[y][x] != 0)
		return true;

	// 해수가 맞다면
	return false;
} 

bool icecheck(int y, int x){
	// 범위를 벗어나면
	if((y<0) || (x<0) || (y>=N) || (x>=M))
		return true;
	// 얼음이 아니라면
	if(map[y][x] == 0)
		return true;

	// 얼음이 맞다면
	return false;
} 

int bfs(){
	int check[301][301] = {0,};
	int total = 0;
	
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){

			if(map[i][j] == 0 || check[i][j] == 1)
				continue;
			// cout<<i<<" "<<j<<endl;
			queue<pair<int, int> > q;
			
			q.push(make_pair(i,j));
			check[i][j] = 1;
			
			while(!q.empty()){
				int y = q.front().first;
				int x = q.front().second;
				q.pop();
				
				for(int k=0; k<4; k++){
					int ny = y + dy[k];
					int nx = x + dx[k];
					
					if(icecheck(ny,nx))
						continue;
					
					if(check[ny][nx] == 0){
						q.push(make_pair(ny,nx));
						check[ny][nx] = 1;
					}
				}
			}

			total++;

			if(total > 1){
				return 2;
			}
		}
	}
	if(total == 0)
		return 0;

	return 1;
}

int sol(){
	int year = 1;
	
	while(true){
		int ice[301][301] = {0,};

		// 녹일 얼음 수 계산
		for(int i=0; i<N; i++){
			for(int j=0; j<M; j++){
				// 빙산이 있다면
				if(map[i][j] != 0){
					
					// 주변 상하좌우 해수 체크
					for(int k=0; k<4; k++){
						
						int ny = i + dy[k];
						int nx = j + dx[k];

						if(seacheck(ny,nx))
							continue;

						// 해당 빙산의 자리에 녹을 만큼의 수 저장
						ice[i][j]++;
					}
				}
			}
		}

		// 얼음 녹이기
		for(int i=0; i<N; i++){
			for(int j=0; j<M; j++){

				int next_ice = map[i][j] - ice[i][j];
				
				if(next_ice < 0)
					map[i][j] = 0;
				else
					map[i][j] = next_ice;
			}
		}

		int result = bfs();
		if(result == 2){
			break;
		}
		else if(result == 0){
			year = 0;
			break;
		}
		year++;
	}

	return year;
}

int main(){
	cin>>N>>M;
	
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			cin>>map[i][j];
	int year = sol();
	cout<<year<<endl;

	return 0;
}