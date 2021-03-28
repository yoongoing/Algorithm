#include <iostream>
#include <queue>
#include <string>

using namespace std;

int N,M;
int map[1001][1001];
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

int check(int y, int x){
    if(y>=1 && x>=1 && y<=N && x<=M)
        return 1;
    return 0;
}

int bfs(){
    queue<pair<pair<int, int>, int> > q;
    int visited[1001][1001][2];
    
    q.push(make_pair(make_pair(1, 1), 1));
    visited[1][1][1] = 1;
    
    while (!q.empty()){
        int y = q.front().first.first;
        int x = q.front().first.second;
        int b = q.front().second;
        q.pop();

        if(y==N && x==M)
            return visited[y][x][b];
        
        for(int dir=0; dir<4; dir++){
            int ny = y + dy[dir];
            int nx = x + dx[dir];

            if(check(ny, nx)){
                if(map[ny][nx] && b) // 가려는 길이 벽이고, 한번도 안뚫어본 벽이라면
                {
                    visited[ny][nx][b-1] = visited[y][x][b] + 1;
                    q.push(make_pair(make_pair(ny,nx), b-1));
                }
                if(!map[ny][nx] && visited[ny][nx][b]==0){
                    visited[ny][nx][b] = visited[y][x][b] + 1;
                    q.push(make_pair(make_pair(ny,nx), b));
                }
            }
        }
    }

    return -1;
}


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>N>>M;
    for(int i=1; i<=N; i++){
        string str;
        cin>>str;
        for(int j=0; j<str.size(); j++){
            map[i][j+1] = str[j] - '0';
        }
    }

    cout<<bfs()<<"\n";

    return 0;
}