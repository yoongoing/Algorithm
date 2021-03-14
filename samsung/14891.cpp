#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// 10101111
// 01111101
// 11001110
// 00000010
// 2
// 3 -1
// 1 1
int map[6][8];

int dx[2] = {-1,1};

int op_dir(int dir){
    if(dir == 1)
        return -1;
    return 1;
}

void print(){
    for(int i=1; i<=4; i++){
        for(int j=0; j<8; j++){
            cout<<map[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}

void shift(int num, int dir){
    // 시계
    if(dir == 1){
        char c = map[num][7];
        for(int i=7; i>0; i--){
            map[num][i] = map[num][i-1];
        }
        map[num][0] = c;
    } 
    else{ // 반시계
        char c = map[num][0];
        for(int i=0; i<7; i++){
            map[num][i] = map[num][i+1];
        }
        map[num][7] = c;
    }
}

void search(int x, int dir){
    queue<pair<int,int> > q;
    int visited[6] = {0,};

    q.push(make_pair(x, dir));
    visited[x] = 1;

    while(!q.empty()){
        x = q.front().first;
        dir = q.front().second;
        
        q.pop();

        for(int i=0; i<2; i++){
            int nx = x + dx[i];

            if(nx < 1 || nx > 4)
                continue;
            
            if((x<nx) && (map[x][2]!=map[nx][6]) && !visited[nx]){
                visited[nx] = 1;
                q.push(make_pair(nx, op_dir(dir)));
            }

            if((nx<x) && (map[nx][2]!=map[x][6]) && !visited[nx]){
                visited[nx] = 1;
                q.push(make_pair(nx, op_dir(dir)));
            }
        }
        shift(x, dir);
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    for(int i=1; i<=4; i++){
        string str;
        cin>>str;
        for(int j=0; j<str.size(); j++)
            map[i][j] = str[j] - '0';
    }

    int K;
    cin>>K;
    for(int i=0; i<K; i++){
        int x, dir;
        cin>>x>>dir;
        search(x, dir);
    }

    int ans = 0;
    int binary[5] = {0, 1, 2, 4, 8};
    for(int i=1; i<=4; i++){
        if(map[i][0] == 1)
            ans += binary[i];
    }
    cout<<ans<<"\n";
    return 0;
}