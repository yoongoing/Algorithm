#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,M,K;
int E[11][11];
int tE[11][11];

int dy[8] = {-1,-1,-1, 0,0, 1,1,1};
int dx[8] = {-1, 0, 1,-1,1,-1,0,1};

vector<int> tree[11][11];

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>N>>M>>K;

	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			cin>>tE[i][j];
			E[i][j] = 5;
		}
	}
	for(int i=0; i<M; i++){
		int y,x,z;
		cin>>y>>x>>z;
		tree[y][x].push_back(z);
	}


	while(K>0){
		// 봄 & 여름
		for(int i=1; i<=N; i++){
			for(int j=1; j<=N; j++){
				if(tree[i][j].size() == 0)
					continue;
				
				int die = 0;
				vector<int> temp;
				
				sort(tree[i][j].begin(), tree[i][j].end());

				for(int k=0; k<tree[i][j].size(); k++){
					if(E[i][j] >= tree[i][j][k]){
						E[i][j] -= tree[i][j][k];
						temp.push_back(tree[i][j][k] + 1);
					}
					else{
						die += (tree[i][j][k]/2);
					}
				}

				tree[i][j].clear();
				for(int k=0; k<temp.size(); k++){
					tree[i][j].push_back(temp[k]);
				}
				E[i][j] += die;
			}
		}

		// 가을
		for(int i=1; i<=N; i++){
			for(int j=1; j<=N; j++){
				if(tree[i][j].size() == 0)
					continue;

				for(int k=0; k<tree[i][j].size(); k++){
					if(tree[i][j][k] % 5 != 0)
						continue;
					for(int k=0; k<8; k++){
						int ny = i + dy[k];
						int nx = j + dx[k];
						if((ny<1) || (nx<1) || (ny>N) || (nx>N))
							continue;

						tree[ny][nx].push_back(1);
					}
				}
			}
		}

		// 겨울
		for(int i=1; i<=N; i++){
			for(int j=1; j<=N; j++){
				E[i][j] += tE[i][j];
			}
		}
		K--;
	}
	int cnt = 0;
	
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			cnt += tree[i][j].size();
		}
	}

	cout<<cnt<<"\n";

	return 0;
}