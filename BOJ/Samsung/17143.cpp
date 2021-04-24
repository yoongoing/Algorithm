#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

struct Info{
    int y,x;
    int speed,dir,size;
};

bool cmp(Info a, Info b){
    return a.size > b.size;
}

int R,C,M;
int sum = 0;
int map[101][101];
Info shark[10005];

int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,1,-1};

int check(int y, int x){
    return y>=1 && x>=1 && y<=R && x<=C;
}

void print(){
    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            cout<<map[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}

int oppo_dir(int dir){
    int oppo;
    if(dir == 0)        oppo = 1;
    else if(dir == 1)   oppo = 0;
    else if(dir == 2)   oppo = 3;
    else if(dir == 3)   oppo = 2;
    return oppo;
}

void doing(int x){
    for(int i=1; i<=R; i++){
        if(map[i][x]!=0){
            int idx = map[i][x]; 
            
            sum += shark[idx].size;
            shark[idx].size = 0; // 상어 죽음처리
            map[i][x] = 0;
            break;
        }
    }
}

void move(){
    
    for(int i=1; i<=M; i++){
        int y = shark[i].y;
        int x = shark[i].x;
        int speed = shark[i].speed;
        int size = shark[i].size;

        if(size == 0) // 죽은 상어라면
            continue;

        int ny = y;
        int nx = x;  
        // cout<<"start : "<<ny<<","<<nx<<"\n";      
        for(int k=0; k<speed; k++){
            ny += dy[shark[i].dir];
            nx += dx[shark[i].dir];

            if(!check(ny, nx)){
                shark[i].dir = oppo_dir(shark[i].dir);
                if(ny>R || ny<1)
                    ny += dy[shark[i].dir] * 2;
                if(nx>C || nx<1)
                    nx += dx[shark[i].dir] * 2;
            }
        }
        // cout<<"end : "<<ny<<","<<nx<<"\n\n";
        shark[i].y = ny;
        shark[i].x = nx;
    }
    memset(map, 0, sizeof(map));
    for(int i=1; i<=M; i++){
        if(shark[i].size == 0) // 죽은 상어는 보지 않음.
            continue;

        int y = shark[i].y;
        int x = shark[i].x;

        if(map[y][x] == 0)
            map[y][x] = i;
        else{
            if(shark[map[y][x]].size < shark[i].size){
                shark[map[y][x]].size = 0;
                map[y][x] = i;
            }
            else
                shark[i].size = 0;
        }
    }
}

void sol(int y, int x){
    for(int k=1; k<=C; k++){
        // 1. 낚시왕이 오른쪽으로 한칸 이동
        y += dy[2];
        x += dx[2];

        // 2. 열에 있는 상어중 땅과 제일 가까운 상어 잡기.
        doing(x);

        // 3. 상어 이동
        move();
        // print();
    }
    cout<<sum<<"\n";
}

int main(void){
    
    cin>>R>>C>>M;
    for(int i=1; i<=M; i++){
        int r,c,s,d,z;
        cin>>r>>c>>s>>d>>z;

        map[r][c] = i;
        if(d==1 || d==2){
            Info F = {r,c,s%(2*R-2),d-1,z};
            shark[i] = F;
        }
        if(d==3 || d==4){
            Info F = {r,c,s%(2*C-2),d-1,z};
            shark[i] = F;
        }
    }

    sol(0,0);
    return 0;
}