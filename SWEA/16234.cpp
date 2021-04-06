#include <iostream>
#include <cstring>
#include <vector>
#include <stdlib.h>

using namespace std;

#define endl '\n'

int map[51][51];
int check[51][51] = {0,};
vector<pair<int, int> > v;

int N,L,R;
int people,num;

int dy[4] = {0,0,-1,1};
int dx[4] = {-1,1,0,0};

void dfs(int y, int x){
	for(int k=0; k<4; k++){
		int ny = y + dy[k];
		int nx = x + dx[k];
		
		if((ny<0) || (nx<0) || (ny>=N) || (nx>=N))
			continue;
		if(check[ny][nx] == 1)
			continue;
		
		int diff = abs(map[y][x] - map[ny][nx]);
		if(diff>=L && diff<=R){
			check[ny][nx] = 1;
			num++;
			people+=map[ny][nx];
			v.push_back(make_pair(ny,nx));
			dfs(ny, nx);
		}
	}
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>N>>L>>R;

	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin>>map[i][j];
		}
	}

	int count = 0;
	while(1){
		memset(check, 0, sizeof(check));

		int flag = 0;
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				if(check[i][j])
					continue;
				check[i][j] = 1;
				people = map[i][j];
				num = 1;

				v.clear();
				v.push_back(make_pair(i,j));
				dfs(i,j);


				if(num >= 2){
					flag = 1;
					for(int i=0; i<v.size(); i++)
						map[v[i].first][v[i].second] = people/num;
				}

			}
		}
		
		if(flag)
			count++;
		else
			break;
	}

	cout<<count<<endl;

	return 0;
}