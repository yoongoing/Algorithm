#include <iostream>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

struct Info{
    int from, to, dist;
};

struct cmp{
    bool operator()(Info a, Info b){
        return a.dist > b.dist;
    }
};

int N,M;
int root[251];
char map[51][51];
int key_num[51][51];

int visited[51][51];
int dist[51][51];

priority_queue<Info, vector<Info>, cmp> pq;
vector<pair<int, int> > key; 

int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

int find(int n){
    if(root[n] == n)
        return n;
    return root[n] = find(root[n]);
}

void Union(int a, int b){
    a = find(a);
    b = find(b);
    root[b] = a;
}

int compare(int a, int b){
    a = find(a);
    b = find(b);
    
    if(a == b)
        return 1;
    return 0;
}

int check(int y, int x){
    return y>=0 && x>=0 && y<N && x<N;
}
    

int bfs(int y, int x, int from){
    int cnt = 1;
    memset(visited, 0, sizeof(visited));
    memset(dist, 0, sizeof(dist));

    queue <pair<int, int> > q;
    q.push(make_pair(y,x));
    visited[y][x] = 1;

    while(!q.empty()){
        y = q.front().first;
        x = q.front().second;
        q.pop();

        // cout<<"(y, x) = ("<<y<<","<<x<<")\n";
        for(int i=0; i<4;i++){
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(check(ny, nx) && map[ny][nx]!='1' && !visited[ny][nx]){
                dist[ny][nx] = dist[y][x] + 1;
                visited[ny][nx] = 1;
                
                // 열쇠일때
                if(map[ny][nx] == 'K'){
                    cnt++;
                    Info tmp = {from, key_num[ny][nx], dist[ny][nx]};
                    pq.push(tmp);
                }
                
                if(cnt == key.size())
                    return cnt;
                q.push(make_pair(ny, nx));
            }
        }
    }
    return cnt;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>N>>M;
    
    
    
    int num = 0;
    for(int i=0; i<N; i++){
        string str;
        cin>>str;
        for(int j=0; j<str.size(); j++){
            map[i][j] = str[j];
            
            if(map[i][j] == 'S')
                map[i][j] = 'K';
            if(map[i][j] == 'K'){
                key_num[i][j] = ++num;
                key.push_back(make_pair(i, j));
            }
        }   
    }
    // cout<<"key size: "<<key.size()<<"\n";
    for(int i=0; i<key.size(); i++){
        // cout<<key[i].first<<" "<<key[i].second<<"\n";
        int kn = bfs(key[i].first, key[i].second, key_num[key[i].first][key[i].second]);

        if(kn != key.size()){
            cout<<"-1\n";
            return 0;
        }       
    }
    
    for(int i=0; i<=key.size(); ++i){
        root[i] = i;
    }

    int ans = 0;
    while(!pq.empty()){
        int from = pq.top().from;
        int to = pq.top().to;
        int dist = pq.top().dist;
        // cout<<"from : "<<from<<"\n";
        // cout<<"to : "<<to<<"\n";
        // cout<<"dist : "<<dist<<"\n\n";
        if(!compare(from, to)){
            Union(from, to);
            ans += dist;
        }
        pq.pop();
    }
    
    cout<<ans<<"\n";
    return 0;
}