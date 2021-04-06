#include <iostream>
#include <vector>
using namespace std;

struct SHARK{
	int y;
	int x;
	int dir;
	int live;
	vector<int> priority[5];
};

struct MAP
{
	vector<int> v;
	int time;
	int shark_idx;	
};

int N,M,K;
MAP map[25][25];
SHARK shark[410];

int dy[5] = {0,-1,1,0,0};
int dx[5] = {0,0,0,-1,1};

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>N>>M>>K;

	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			int a;
			cin>>a;
			if(a != 0){
				shark[a].y = i;
				shark[a].x = j;
			}
		}
	}
	return 0;
}