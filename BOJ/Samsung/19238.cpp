#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

struct Info{
    long long cost;
    int y,x;
};

bool cmp(Info a, Info b){
    if(a.cost < b.cost)
        return true;
    else if(a.cost == b.cost){
        if(a.y < b.y)
            return true;
        else if(a.y == b.y){
            if(a.x < b.x)
                return true;
            return false;
        }
        return false;
    }
    return false;
}

int N,M;
long long K;
int arr[21][21];
int customer[21][21];
vector<int> arrival[21][21];
pair<int, int> start;
map<pair<int, int>, pair<int, int> > m;

pair<int, int> nxt;
long long next_cost;

int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

int check(int y, int x){
    return y>=1 && x>=1 && y<=N && x<=N;
}

int c_bfs(){
    queue<pair<int, int> > q;
    int visited[21][21] = {0,};
    long long cost[21][21] = {0,};

    if(customer[start.first][start.second] != 0){
        next_cost = 0;
        nxt.first = start.first;
        nxt.second = start.second;
        return 1;
    }
    q.push(make_pair(start.first, start.second));
    visited[start.first][start.second] = 1;

    vector<Info> v;
    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(check(ny, nx)){
                if(!visited[ny][nx] && !arr[ny][nx]){
                    visited[ny][nx] = 1;
                    cost[ny][nx] = cost[y][x] + 1;
                    q.push(make_pair(ny, nx));

                    if(customer[ny][nx] != 0){
                        Info temp = {cost[ny][nx], ny, nx};
                        v.push_back(temp);    
                    }
                }
            }
        }
    }
    if(v.size() == 0)
        return 0;

    sort(v.begin(), v.end(), cmp);
    customer[v[0].y][v[0].x] = 0;
    nxt.first = v[0].y;
    nxt.second = v[0].x;
    next_cost = v[0].cost;
    
    return 1;
}

int a_bfs(){
    queue<pair<int, int> > q;
    int visited[21][21] = {0,};
    long long cost[21][21] = {0,};
    cout<<nxt.first<<","<<nxt.second<<"\n";
    if(m[make_pair(nxt.first, nxt.second)] == make_pair(start.first, start.second)){
        next_cost = 0;
        return 1;
    }

    q.push(make_pair(start.first, start.second));
    visited[start.first][start.second] = 1;
    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(check(ny, nx)){
                if(!visited[ny][nx] && !arr[ny][nx]){
                    visited[ny][nx] = 1;
                    cost[ny][nx] = cost[y][x] + 1;
                    q.push(make_pair(ny, nx));

                    if(m[make_pair(nxt.first, nxt.second)] == make_pair(ny, nx)){
                        arrival[ny][nx] = 0;
                        nxt.first = ny;
                        nxt.second = nx;
                        next_cost = cost[ny][nx];
                        
                        return 1;    
                    }
                }
            }
        }
    }

    return 0;
}

void sol(){
    int flag = 0;
    for(int i=0; i<M; i++){
        int result = c_bfs();
        
        if(!result){ // 못간다면
            cout<<"-1";
            return;
        }
        
        if(next_cost > K){ // 연료가 부족하다면
            cout<<"-1";
            return;
        }
        
        cout<<next_cost<<"\n";

        K -= next_cost;
        start.first = nxt.first;
        start.second = nxt.second;

        result = a_bfs();

        if(!result){ // 못간다면
            cout<<"-1";
            return;
        }
        
        if(next_cost > K){ // 연료가 부족하다면
            cout<<"-1";
            return;
        }

        cout<<next_cost<<"\n";
        

        K -= next_cost;
        K += next_cost * 2;
        start.first = nxt.first;
        start.second = nxt.second;
    }

    cout<<K<<"\n";
}

int main(void){
    cin>>N>>M>>K;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin>>arr[i][j];
        }
    }
    cin>>start.first>>start.second;

    for(int i=1; i<=M; i++){
        int y1,x1,y2,x2;
        cin>>y1>>x1>>y2>>x2;
        
        m[make_pair(y1,x1)] = make_pair(y2,x2);
        customer[y1][x1] = i;
        arrival[y2][x2].push_back(i);
    }
    sol();
    
    return 0;
}