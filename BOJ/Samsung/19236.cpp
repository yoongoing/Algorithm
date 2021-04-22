#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

struct Fish{
    int dir;
    int y,x;
};


int result = 0;
Fish fishes[17] = {0,};
int map[5][5] = {0,};

int dy[8] = {-1,-1,0,1,1,1,0,-1};
int dx[8] = {0,-1,-1,-1,0,1,1,1};

int check(int y, int x){
    return y>=0 && x>=0 && y<4 && x<4;
}

void print(){
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            cout<<map[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}

void move(){
    for(int i=1; i<=16; i++){
        int y = fishes[i].y;
        int x = fishes[i].x;
        int d = fishes[i].dir;
        
        if(d == -1)
            continue;

        int dir = d;
        for(int k=0; k<8; k++){
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            
            // 범위 안이라면
            if(check(ny, nx)){
                int idx = map[ny][nx];
                
                // 상어라면 피하기
                if(idx == 0){
                    dir = (dir+1) % 8;
                    continue;
                }
                
                map[y][x] = idx;
                fishes[i].y = ny;
                fishes[i].x = nx;
                fishes[i].dir = dir;

                map[ny][nx] = i;
                fishes[idx].y = y;
                fishes[idx].x = x;
                break;
            }
            dir = (dir + 1) % 8;
        }
    }
}

void dfs(int y, int x, int dir, int sum){
    Fish ftemp[17];
    int temp[5][5];

    for(int i=1; i<=16; i++)
        ftemp[i] = fishes[i];
    memcpy(temp, map, sizeof(temp));

    // 물고기 이동
    move();
    
    int ny = y;
    int nx = x;
    while (1)
    {
        ny += dy[dir];
        nx += dx[dir];

        if(check(ny, nx)){
            int idx = map[ny][nx];

            if(idx == -1)
                continue;

            int fdir = fishes[idx].dir;
            
            fishes[idx].dir = -1; // 물고기가 죽었다고 표시
            map[y][x] = -1; // 상어가 왔었다고 표시
            map[ny][nx] = 0; // 상어 위치 변경
            
            dfs(ny, nx, fdir, sum+idx);

            fishes[idx].dir = fdir; // 물고기가 죽었다고 표시
            map[y][x] = 0; // 상어가 왔었다고 표시
            map[ny][nx] = idx; // 상어 위치 변경
        }
        else
            break;
    }
    result = max(result, sum);
    
    for(int i=1; i<=16; i++)
        fishes[i] = ftemp[i];
    memcpy(map, temp, sizeof(map));

    return;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            int idx, dir;
            cin>>idx>>dir;
            
            map[i][j] = idx;
            fishes[idx].y = i;
            fishes[idx].x = j;
            fishes[idx].dir = dir - 1;
        }
    }

    int val = map[0][0];
    int dir = fishes[val].dir;
    
    fishes[val].dir = -1;
    map[0][0] = 0;

    dfs(0, 0, dir, val);
    cout<<result<<"\n";
    return 0;
}