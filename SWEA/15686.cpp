#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define MAX_INF 987654321

int N,M,csize,hsize;
int map[51][51];
int chk[101] = {0,};

vector<pair<int, int> > chicken;
vector<pair<int, int> > house;


int MIN  = 987654321;

void dfs(int idx, int cnt){
	if(idx > chicken.size()){
		return;
	}
	if(cnt == M){
		int cmp = 0;

        for (int i = 0; i < house.size(); i++)
        {
            int dist = MAX_INF;
            for (int j = 0; j < chicken.size(); j++)
            {
                if (chk[j])
                {
                    int px = house[i].first, py = house[i].second;
                    int samx = chicken[j].first, samy = chicken[j].second;
                    int d = abs(px - samx) + abs(py - samy);
                    dist = min(dist, d);
                }
            }
            cmp += dist;
        }

        MIN = min(MIN, cmp);

        return;
	}

	chk[idx] = 1;
	dfs(idx+1, cnt+1);

	chk[idx] = 0;
	dfs(idx+1, cnt);
}

int main(int argc, char const *argv[])
{
	cin>>N>>M;

	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin>>map[i][j];
			if(map[i][j] == 2){
				chicken.push_back(make_pair(i,j));
			}
			if(map[i][j] == 1){
				house.push_back(make_pair(i,j));
			}
		}
	}

	csize = chicken.size();
	hsize = house.size();

	dfs(0, 0);
	cout<<MIN<<"\n";

	return 0;
}










