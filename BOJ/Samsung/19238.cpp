#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct Info{
    int y,x,cost;
};

bool cmp(Info a, Info b){
    if(a.cost == b.cost){
        if(a.x == b.x)
            return a.y < b.y;
        return a.x < b.x;
    }
    return a.cost < b.cost;
}

int N,M, tk;
int road[21][21];
int ty, tx; // 택시위치
int S[21][21];
int E[21][21];

int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

int check(int y, int x){
    return y>=1 && x>=1 && y<=N && x<=N;
}

Info passenger(){
    vector<Info> next;
    queue<pair<int, int> > q;
    int visited[21][21] = {0,};
    int dist[21][21] = {0,};

    visited[ty][tx] = 1;
    q.push(make_pair(ty, tx));

    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int dir=0; dir<4; dir++){
            int ny = y + dy[dir];
            int nx = x + dx[dir];

            if(check(ny, nx) && !road[ny][nx] && !visited[ny][nx]){
                visited[ny][nx] = 1;
                dist[ny][nx] = dist[y][x] + 1;
                q.push(make_pair(ny, nx));

                if(S[ny][nx] > 0){
                    Info temp = {ny, nx, dist[ny][nx]};
                    next.push_back(temp);
                }
            }
        }
    }
    if(next.size() == 0){
        Info temp = {0,0,0};
        return temp;
    }

    sort(next.begin(), next.end(), cmp);
    return next[0];
}

Info destination(int num){
    queue<pair<int, int> > q;
    int visited[21][21] = {0,};
    int dist[21][21] = {0,};

    visited[ty][tx] = 1;
    q.push(make_pair(ty, tx));

    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int dir=0; dir<4; dir++){
            int ny = y + dy[dir];
            int nx = x + dx[dir];

            if(check(ny, nx) && !road[ny][nx] && !visited[ny][nx]){
                visited[ny][nx] = 1;
                dist[ny][nx] = dist[y][x] + 1;
                q.push(make_pair(ny, nx));

                if(E[ny][nx] == num){
                    Info temp = {ny, nx, dist[ny][nx]};
                    return temp;
                }
                    
            }
        }
    }
    Info temp = {0,0,0};
    return temp;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>N>>M>>tk;
    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++)
            cin>>road[i][j];
    cin>>ty>>tx;

    int num = 1;
    for(int i=0; i<M; i++){
        int sy,sx,ey,ex;
        cin>>sy>>sx>>ey>>ex;
        S[sy][sx] = num;
        E[ey][ex] = num++;
    }

    int cnt = 0;
    while (1){
        Info from = passenger();
        if(tk < from.cost || from.cost == 0){
            cout<<"-1\n";
            return 0;
        }
        num = S[from.y][from.x];
        S[from.y][from.x] = 0;
        ty = from.y;
        tx = from.x;
        tk -= from.cost;
        // cout<<"ty : "<<ty<<", tx : "<<tx<<"\n";
        // cout<<"cost : "<<from.cost<<", so tk is "<<tk<<"\n";

        Info to = destination(num);
        if(tk < to.cost || to.cost == 0){
            cout<<"-1\n";
            return 0;
        }
        E[to.y][to.x] = 0;
        ty = to.y;
        tx = to.x;
        tk -= to.cost;
        tk += to.cost * 2;

        cnt++;
        // cout<<"ty : "<<ty<<", tx : "<<tx<<"\n";
        // cout<<"cost : "<<to.cost<<", so tk is "<<tk<<"\n";
        if(cnt == M){
            cout<<tk<<"\n";
            break;
        }
        
        // cout<<"=========================\n";
    }
    
    return 0;
}