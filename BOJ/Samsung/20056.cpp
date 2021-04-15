#include <iostream>
#include <vector>

using namespace std;

struct Magic{
    int m;
    int s;
    int d;
};

int N,M,K;
vector<Magic> v[52][52];

int dr[8] = {-1,-1,0,1,1,1,0,-1};
int dc[8] = {0,1,1,1,0,-1,-1,-1};

int check(int r, int c){
    return r>=1 && c>=1 && r<=N && c<=N;
}

void move(){
    vector<Magic> tv[52][52];

    for(int r=1; r<=N; r++){
        for(int c=1; c<=N; c++){
            // 모든 파이어볼이
            for(int i=0; i<v[r][c].size(); i++){
                int m = v[r][c][i].m;
                int s = v[r][c][i].s;
                int d = v[r][c][i].d;

                // 자신의 방향 d로 속력 s칸 만큼 이동
                int nr = r + dr[d] * s;
                int nc = c + dc[d] * s;

                if(check(nr, nc)){
                    tv[nr][nc].push_back(v[r][c][i]);
                }
                else{
                    if(nr > N)   nr = nr%N;
                    if(nr < 1)   nr = N - abs(nr) % N;
                    if(nc > N)   nc = nc%N;
                    if(nc < 1)   nc = N - abs(nc) % N;
                    
                    tv[nr][nc].push_back(v[r][c][i]);
                }
            }
            v[r][c].clear();
        }       
    }

    for(int r=1; r<=N; r++){
        for(int c=1; c<=N; c++){
            v[r][c] = tv[r][c];
        }
    }
}

void cal(){
    for(int r=1; r<=N; r++){
        for(int c=1; c<=N; c++){
            // 2개 이상의 파이어볼이 있는 칸에서는
            if(v[r][c].size() >= 2){
 
                int M=0, S=0, D=0;
                
                // 같은 칸에 있는 파이어볼은 모두 하나로 합쳐진다
                for(int i=0; i<v[r][c].size(); i++){
                    M += v[r][c][i].m;
                    S += v[r][c][i].s;
                    D += v[r][c][i].d % 2;
                }
                
                // 질량은 ⌊(합쳐진 파이어볼 질량의 합)/5⌋
                int nm = M / 5;

                // 속력은 ⌊(합쳐진 파이어볼 속력의 합)/(합쳐진 파이어볼의 개수)⌋
                int ns = S / v[r][c].size();
                
                int nd[4];
                // 합쳐지는 파이어볼의 방향이 모두 홀수이거나 모두 짝수이면
                if(D==0 || D==v[r][c].size()){
                    // 방향은 0, 2, 4, 6
                    nd[0] = 0;
                    nd[1] = 2;
                    nd[2] = 4;
                    nd[3] = 6; 
                }
                // 그렇지 않으면
                else{
                    // 방향은 1, 3, 5, 7
                    nd[0] = 1;
                    nd[1] = 3;
                    nd[2] = 5;
                    nd[3] = 7;
                }
                
                v[r][c].clear();
                // 질량이 0인 파이어볼은 소멸되어 없어진다
                if(nm == 0)
                    continue;
                
                vector<Magic> temp;
                for(int i=0; i<4; i++){
                    Magic temp = {nm, ns, nd[i]};
                    v[r][c].push_back(temp);
                }
            }
        }
    }
}

int sol(int sum){
    for(int r=1; r<=N; r++){
        for(int c=1; c<=N; c++){
            for(int i=0; i<v[r][c].size(); i++){
                sum += v[r][c][i].m;
            }
        }
    }
    return sum;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>N>>M>>K;
    for(int i=0; i<M; i++){
        // 위치(r,c), 질량 m, 방향 d, 속력 s
        int r,c,m,s,d;
        cin>>r>>c>>m>>s>>d;
        Magic temp = {m, s, d};
        v[r][c].push_back(temp);
    }

    // K번 이동
    for(int i=0; i<K; i++){
        move();
        cal();
    }
    cout<<sol(0)<<"\n";
    return 0;
}

/*
#include <iostream>
#include <vector>

using namespace std;

struct Ball{
    int m,s,d;
}; 

int N,M,K;
vector<Ball> map[52][52];

int dr[8] = {-1,-1,0,1,1,1,0,-1};
int dc[8] = {0,1,1,1,0,-1,-1,-1};

void move(){
    vector<Ball> temp[52][52];
    for(int r=1; r<=N; r++){
        for(int c=1; c<=N; c++){

            for(int k=0; k<map[r][c].size(); k++){
                int m = map[r][c][k].m;
                int speed = map[r][c][k].s;
                int dir = map[r][c][k].d;

                // 자신의 방향 d로 속력 s칸 만큼 이동
                int nr = r + dr[dir] * speed;
                int nc = c + dc[dir] * speed;

                if(nr > N)  nr %= N;
                if(nr < 1)  nr = N - ((-1 * nr) % N);
                if(nc > N)  nc %= N;
                if(nc < 1)  nc = N - ((-1 * nc) % N);
                // cout<<r<<", "<<c<<" to "<<nr<<", "<<nc<<"\n";
                
                temp[nr][nc].push_back(map[r][c][k]);
            }
            map[r][c].clear();
        }
    }
    for(int r=1; r<=N; r++)
        for(int c=1; c<=N; c++)
            map[r][c] = temp[r][c];
}

void work(){
    for(int r=1; r<=N; r++){
        for(int c=1; c<=N; c++){

            // 2개 이상의 파이어볼이 있는 칸에서만
            if(map[r][c].size() > 1){
                int size = map[r][c].size();

                int next_m = 0;
                int next_s = 0;
                int next_dir = 0;

                for(int k=0; k<size; k++){
                    next_m += map[r][c][k].m;
                    next_s += map[r][c][k].s;
                    next_dir += (map[r][c][k].d % 2);
                }
                map[r][c].clear();

                // 질량은 ⌊(합쳐진 파이어볼 질량의 합)/5⌋
                next_m /= 5;

                // 질량이 0인 파이어볼은 소멸
                if(next_m == 0)
                    continue;

                // 속력은 ⌊(합쳐진 파이어볼 속력의 합)/(합쳐진 파이어볼의 개수)⌋
                next_s /= size;

                int dir[4];
                // 합쳐지는 파이어볼의 방향이 모두 홀수이거나 모두 짝수이면
                if(next_dir==0 || next_dir==size){
                    dir[0] = 0;
                    dir[1] = 2;
                    dir[2] = 4;
                    dir[3] = 6;
                }
                else{
                    dir[0] = 1;
                    dir[1] = 3;
                    dir[2] = 5;
                    dir[3] = 7;
                }

                for(int k=0; k<4; k++){
                    Ball B = {next_m, next_s, dir[k]};
                    map[r][c].push_back(B);
                }
            }
        }
    }
}

int count(int sum){
    for(int r=1; r<=N; r++)
        for(int c=1; c<=N; c++)        
            for(int k=0; k<map[r][c].size(); k++)
                sum += map[r][c][k].m;
    return sum;
}

int sol(){
    for(int step=0; step<K; step++){
        // 1
        move();

        // 2
        work();
    }
    return count(0);
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>N>>M>>K;
    for(int i=0; i<M; i++){
        int r, c, m, s, d;
        cin>>r>>c>>m>>s>>d;
        
        Ball B = {m, s, d};
        map[r][c].push_back(B);
    }

    cout<<sol()<<"\n";
}
*/