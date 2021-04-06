#include <stdio.h>
#include <string>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;



int N;
int groupID = 0;
int group[26*26];

int data[26][26];
bool visited[26][26];



int dy[] = {-1,1,0,0};
int dx[] = {0,0,1,-1};

void bfs(int y, int x)
{
	queue<pair<int,int> > q;
	q.push(make_pair(y,x));

	visited[y][x] = true;
	group[groupID]++;

	while(!q.empty()){
		y = q.front().first;
		x = q.front().second;
		q.pop();
		

		for(int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];

			if( ny >= 0 && nx >= 0 && ny < N && nx < N ){	
				if((visited[ny][nx] == false) && (data[ny][nx] == 1)){
					visited[ny][nx] = true;
					group[groupID]++;	
					q.push(make_pair(ny,nx));
				}
			}
		}
	}
}

void dfs(int y,int x)
{
	visited[y][x] = true;
	group[groupID]++;

	for(int i = 0; i < 4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];

		if( ny >= 0 && nx >= 0 && ny < N && nx < N ){	
			if((visited[ny][nx] == false) && (data[ny][nx] == 1))
				dfs(ny,nx);
		}
	}
}

int main(int argc, char const *argv[])
{
	string str;

	cin >> N;

	for(int i=0; i<N; i++){
		cin >> str;
		for(int j=0; j<N; j++){
			data[i][j] = str.at(j) - 48;
		}
	}

	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(data[i][j] == 1 && visited[i][j] == false){
				groupID++;
				//dfs(i,j);
				bfs(i,j);
			}
		}
	}	

	sort(group+1, group+groupID+1);
	cout<<groupID<<endl;

	for(int i=1; i<=groupID; i++)
		cout<<group[i]<<endl;

	return 0;
}