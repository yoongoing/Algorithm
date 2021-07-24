#include <iostream>
#include <queue>

using namespace std;

int N,M,K;
int map[101][101] = {0,};
int visited[101][101] = {0,};

int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

int ans = 0;

int check(int y, int x){
    return y>=1 && y<=N && x>=1 && x<=M;
}

void bfs(int y, int x){
    queue<pair<int, int> > q;
    
    q.push(make_pair(y, x));
    visited[y][x] = 1;

    int count = 1;
    while(!q.empty()){
        y = q.front().first;
        x = q.front().second;
        q.pop();

        for(int k=0; k<4; k++){
            int ny = y + dy[k];
            int nx = x + dx[k];
            
            if(check(ny, nx) && !visited[ny][nx] && map[ny][nx]){
                visited[ny][nx] = 1;
                count++;
                q.push(make_pair(ny, nx));
            }
        }
    }

    ans = max(ans, count);
}

int main(void){
    cin>>N>>M>>K;
    for(int i=0; i<K; i++){
        int y, x;
        cin>>y>>x;
        map[y][x] = 1;
    }
    
    for(int y=1; y<=N; y++){
        for(int x=1; x<=M; x++){
            if(!visited[y][x] && map[y][x]){
                bfs(y,x);
            }
        }
    }

    cout<<ans<<"\n";
    return 0;
}