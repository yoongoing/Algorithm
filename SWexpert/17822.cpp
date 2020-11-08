#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 52

int N,M,T;
int map[MAX][MAX];

int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

void print(){
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++)
			cout<<map[i][j]<<" ";
		cout<<"\n";
	}
}

void push_map(int idx, int dir, int n){
	for(int K=0; K<n; K++){
		if(dir == 0){
			for(int j=M; j>=1; j--){
				map[idx][j] = map[idx][j-1];
			}
			map[idx][0] = map[idx][M];
			map[idx][M+1] = map[idx][1];
		}
		else if(dir == 1){
			for(int j=1; j<=M; j++){
				map[idx][j] = map[idx][j+1];
			}
			map[idx][0] = map[idx][M];
			map[idx][M+1] = map[idx][1];
		}
	}
}

void del(){
	int flag = 0;
	int summ = 0;
	int de = 0;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			if(map[i][j] == -1 || map[i][j] == 0)
				continue;
			summ += map[i][j];
			de++;
			int cnt = 1;
			int temp = map[i][j];

			int check[MAX][MAX] = {0,};
			queue<pair<int, int> > q;
			map[i][j] = -1;
			q.push(make_pair(i,j));
			check[i][j] = 1;

			while(!q.empty()){
				int y = q.front().first;
				int x = q.front().second;
				q.pop();

				for(int k=0; k<4; k++){
					int ny = y + dy[k];
					int nx = x + dx[k];

					if((ny<1) || (ny>M))
						continue;

					if(nx == 0)
						nx = M;
					if(nx == M+1)
						nx = 1;

					if(!check[ny][nx] && map[ny][nx] != -1){
						if(temp == map[ny][nx]){
							check[ny][nx] = 1;
							q.push(make_pair(ny,nx));
							map[ny][nx] = -1;
							cnt++;
							if(nx == 1)
								map[ny][M+1] = map[ny][nx];
							else if(nx == M)
								map[ny][0] = map[ny][nx];
						}
					}
				}
			}
			if(cnt == 1)
				map[i][j] = temp;

			else{
				flag = 1;
				if(j == 1)
					map[i][M+1] = map[i][j];
				else if(j == M)
					map[i][0] = map[i][j];		
			}
		}
	}
	if(flag == 0){
		int mean = summ/de;
		int re = summ%de;

		for(int i=1; i<=N; i++){
			for(int j=1; j<=M; j++){
				if(map[i][j] == -1)
					continue;
				if(map[i][j] < mean){
					map[i][j]++;
				}
				else if(map[i][j] == mean){
					if(re > 0)
						map[i][j]++;
				}
				else if(map[i][j] > mean){
					map[i][j]--;
				}

				if(j==1)
					map[i][M+1] = map[i][j];
				if(j==M)
					map[i][0] = map[i][j];
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>N>>M>>T;

	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			cin>>map[i][j];
		}
		map[i][0] = map[i][M];
		map[i][M+1] = map[i][1];
	}

	for(int K=0; K<T; K++){
		int x,d,k;
		cin>>x>>d>>k;

		for(int i=1; i<=N; i++){
			if(i % x == 0){	// x의 배수면
				push_map(i, d, k);
			}
		}
		// print();
		del();
		// print();
	}

	int sum = 0;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			if(map[i][j] == -1)
				continue;
			sum += map[i][j];
		}
	}
	cout<<sum<<"\n";

	return 0;
}