#include <iostream>
#include <vector>

using namespace std;

struct cctv{
    int y,x,num;
};

int N,M;
int office[9][9];
int tmp_office[9][9];
int visited[9][9][4] = {0,};

vector<cctv> v;
vector<int> angle;

int dy[4] = {0,-1,0,1};
int dx[4] = {-1,0,1,0};

int result = 987654321;

int check(int y, int x){
    if((y<0) || (x<0) || (y>=N) || (x>=M))
        return 0;
    return 1;
}

int count(int cnt){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(tmp_office[i][j] == 0)
                cnt++;
        }
    }
    return cnt;
}

void copy(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            tmp_office[i][j] = office[i][j];
        }
    }
}

void dfs(int cnt){
    if(cnt == v.size()){
        for(int i=0; i<angle.size(); i++){
            int y = v[i].y;
            int x = v[i].x;


            for(int j=0; j<4; j++){
                if(!visited[y][x][j])
                    continue;

                // 각도 + 원 방향 => 비추는곳
                int ny = y + dy[ (angle[i] + j) % 4 ]; 
                int nx = x + dx[ (angle[i] + j) % 4 ];
                
                while(1){
                    if(tmp_office[ny][nx] == 6)
                        break;
                    
                    if(!check(ny, nx))
                        break;
                        
                    
                    if(tmp_office[ny][nx] == 0)
                        tmp_office[ny][nx] = -1;
                    
                    ny += dy[ (angle[i] + j) % 4 ];
                    nx += dx[ (angle[i] + j) % 4 ];
                }
            }
        }
        result = min(result, count(0));
        copy();
        return;
    }

    for(int i=0; i<4; i++){
        angle.push_back(i);
        dfs(cnt + 1);
        angle.pop_back();
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>N>>M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>office[i][j];
            if(0 < office[i][j] && office[i][j] < 6){
                cctv c = {i, j, office[i][j]};
                v.push_back(c);
            }

            if(office[i][j] == 1){
                visited[i][j][0] = 1;
            }
            else if(office[i][j] == 2){
                visited[i][j][0] = 1;
                visited[i][j][2] = 1;
            }
            else if(office[i][j] == 3){
                visited[i][j][0] = 1;
                visited[i][j][1] = 1;
            }
            else if(office[i][j] == 4){
                visited[i][j][0] = 1;
                visited[i][j][1] = 1;
                visited[i][j][2] = 1;
            }
            else if(office[i][j] == 5){
                visited[i][j][0] = 1;
                visited[i][j][1] = 1;
                visited[i][j][2] = 1;
                visited[i][j][3] = 1;
            }
        }
    }
    copy();
    dfs(0);

    cout<<result<<"\n";
    return 0;
}