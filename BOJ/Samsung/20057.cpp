#include <iostream>

using namespace std;

int N;
int A[500][500];
int dir_y[2501];
int dir_x[2501];
int dy[4] = {0,1,0,-1};
int dx[4] = {-1,0,1,0};
int start_i, start_j;
int by[4][10] = {{-1, 1,-2, 2,-1, 1,-1, 1, 0, 0},\
                 {-1,-1, 0, 0, 0, 0, 1, 1, 2, 1},\
                 { 1,-1, 2,-2, 1,-1, 1,-1, 0, 0},\
                 { 1, 1, 0, 0, 0, 0,-1,-1,-2,-1}};

int bx[4][10] = {{ 1, 1, 0, 0, 0, 0,-1,-1,-2,-1},\
                 {-1, 1,-2, 2,-1, 1,-1, 1, 0, 0},\
                 {-1,-1, 0, 0, 0, 0, 1, 1, 2, 1},\
                 { 1,-1, 2,-2, 1,-1, 1,-1, 0, 0}};

int rat[9] = {1,1,2,2,7,7,10,10,5};

void print(){
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++)
            cout<<A[i][j]<<" ";
        cout<<"\n";
    }
    cout<<"\n";
}

int check(int y, int x){
    if(y>=1 && x>=1 && y<=N && x<=N)
        return 1;
    return 0;
}

int blow(int y, int x, int dir){
    //cout<<y<<", "<<x<<"\n";
    int sand = 0; // 격자 밖으로 나간 모래
    int alpha = 0;// 밀린 모래
    int cur = A[y][x];

    for(int i=0; i<10; i++){
        int r_sand;
        if(i != 9){
            r_sand = cur * rat[i] / 100;
            A[y][x] -= r_sand;
        }
        else
            r_sand = A[y][x];

        int ny = y + by[dir][i];
        int nx = x + bx[dir][i];

        if(!check(ny, nx)){
            sand += r_sand;
            continue;
        }
        A[ny][nx] += r_sand;
    }

    A[y][x] = 0;

    return sand;
}

void sol(void){
    int y = (N+1)/2;
    int x = y;
    
    int sand = 0;
    int k = 0;
    // 2번씩
    for(double i=1.0; i<=N; i+=0.5){
        for(int j=0; j<(int)i; j++){
            y += dy[k%4];
            x += dx[k%4];
            sand += blow(y, x, k%4);
        }
        k++;
    }
    cout<<sand<<"\n";
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>N;
     
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++)
            cin>>A[i][j];
    }

    sol();
    
    return 0;
}