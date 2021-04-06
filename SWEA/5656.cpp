#include <iostream>
#include <queue>
#include <math.h>

using namespace std;

int n,w,h;
int map[15][12];
int ans =987654321;

bool check(int y, int x){
	if((y<0) || (x<0) || (y>h-1) || (x>w-1))
		return true;
	return false;
}
int count(){
	int total = 0;
		for(int i=0; i<h; i++)
			for(int j=0; j<w; j++)
				if(map[i][j] != 0)
					total++;
	return total;
}


void re_map(){
	for (int i = 0; i < w; i++) {
        for (int j = h-1; j >=1; j--) {
            for (int k = j - 1; k >= 0; k--) {
                if (map[j][i] != 0) break;
                if (map[k][i] != 0) {
                    map[j][i] = map[k][i];
                    map[k][i] = 0;
                    break;
                }
            }
        }
    }
}

void shoot(int idx){
	queue <pair<int, int> > q;
	bool checker[15][12]={0,};

	for(int i=0; i<h; i++){
		if(map[i][idx] > 0){
			q.push(make_pair(i,idx));
			break;
		}
	}

	while(!q.empty()){
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		int spread = map[y][x];
		
		map[y][x] = 0;

		for(int next=1; next<spread; next++){
			if(!check(y,x+next) && map[y][x+next]>0 && !checker[y][x+next]){
				checker[y][x+next] = true;
				q.push(make_pair(y,x+next));
			}

			if(!check(y,x-next) && map[y][x-next]>0 && !checker[y][x-next]){
				checker[y][x-next] = true;
				q.push(make_pair(y,x-next));
			}					

			if(!check(y+next,x) && map[y+next][x]>0 && !checker[y+next][x]){
				checker[y+next][x] = true;
				q.push(make_pair(y+next,x));	
			}					

			if(!check(y-next,x) && map[y-next][x]>0 && !checker[y-next][x]){
				checker[y-next][x] = true;
				q.push(make_pair(y-next,x));
			}
		}
	}
	re_map();
}

void dfs(int cnt){
	if(cnt == n){
		ans = min(ans,count());
		return;
	}

	int cpy_map[15][12];

	for(int i=0; i<h; i++)
		for(int j=0; j<w; j++)
			cpy_map[i][j] = map[i][j];

	 
	for(int i=0; i<w; i++){
		shoot(i);
		dfs(cnt+1);

		for(int i=0; i<h; i++)
			for(int j=0; j<w; j++)
				map[i][j] = cpy_map[i][j];	
	}
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;

	for(int test_case=1; test_case<=t; test_case++){
		cin>>n>>w>>h;

		for(int i=0; i<h; i++)
			for(int j=0; j<w; j++)
				cin>>map[i][j];
		
		dfs(0);
		
		cout<<"#"<<test_case<<" "<<ans<<endl;
		ans = 987654321;
	}

	return 0;
}