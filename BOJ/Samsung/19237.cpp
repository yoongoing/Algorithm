#include <iostream>
#include <cstring>

using namespace std;

struct Info{
    int y,x;
    int dir;
    bool dead;
};
struct MInfo{
    int idx, k;
};

int N,M,K;
int total;

Info shark[401]; // 상어 정보 저장
MInfo map[20][20]; // 향과 상어 고유번호 저장
int dup[20][20];

int prefer[410][4][4];
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

int check(int y, int x){
    return y>=0 && x>=0 && y<N && x<N;
}
void print(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++)
            cout<<"("<<map[i][j].idx<<","<<map[i][j].k<<") ";
        cout<<"\n";
    }
    cout<<"\n";
}

void init(){
    for(int i=1; i<=M; i++){
        if(shark[i].dead)
            continue;
        map[shark[i].y][shark[i].x].k = K;
        map[shark[i].y][shark[i].x].idx = i;
    }
}


void sol(){
    int ans = 1;
    while (ans<=1000){
        // 1. 상어 배치
        init();
        // print();
        // 2. 상어 움직이기
        memset(dup, 0, sizeof(dup));

        for(int i=1; i<=M; i++){
            
            if(shark[i].dead) // 상어가 죽었다면
                continue;

            int y = shark[i].y;
            int x = shark[i].x;
            int look = shark[i].dir;
            
            int own = -1;
            int flag = 0;

            for(int dir=0; dir<4; dir++){
                int k = prefer[i][look][dir];
                int ny = y + dy[k];
                int nx = x + dx[k];

                if(check(ny, nx)){
                    if(map[ny][nx].k == 0){
                        shark[i].y = ny;
                        shark[i].x = nx;
                        shark[i].dir = k;
                        
                        flag = 1;
                        break;
                    }

                    else{
                        // 자기 냄새인데 최초 발견할때만(우선순위 고려)
                        if(map[ny][nx].idx==i && own==-1)
                            own = k;
                    }
                }
            }

            if(!flag && own!=-1){
                int ny = y + dy[own];
                int nx = x + dx[own];

                shark[i].y = ny;
                shark[i].x = nx;
                shark[i].dir = own;
            }
        }
        // 3. 상어 냄새 관리
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(map[i][j].k > 0)
                    map[i][j].k--;
                
                if(map[i][j].k == 0)
                    map[i][j].idx = 0;
            }
        }
        // 4. 겹침 처리
        for(int i=1; i<=M; i++){
            if(shark[i].dead)
                continue;
            
            int y = shark[i].y;
            int x = shark[i].x;

            if(dup[y][x] != 0)
                shark[i].dead = true;
            else{
                dup[y][x] = i;
                map[y][x].idx = i;
                map[y][x].k = K;
            }
                
        }
        
        // 5. 상어 마릿수 체크
        int flag = 1;
        for(int i=2; i<=M; i++){
            if(!shark[i].dead){
                flag = 0;
                break;
            }
        }
        if(flag == 1){
            cout<<ans<<"\n";
            return;
        }
        ans++;
    }
    cout<<"-1\n";
}

int main(void){
    cin>>N>>M>>K;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            int idx;
            cin>>idx;

            if(idx != 0){
                map[i][j].idx = idx;
                
                shark[idx].y = i;
                shark[idx].x = j;
            }
        }
    }

    for(int i=1; i<=M; i++){
        int dir;
        cin>>dir;
        shark[i].dir = dir - 1;
    }

    for(int i=1; i<=M; i++){
        for(int y=0; y<4; y++){
            for(int x=0; x<4; x++){
                int dir;
                cin>>dir;
                prefer[i][y][x] = dir - 1;
            }
        }        
    }
    sol();
    return 0;
}