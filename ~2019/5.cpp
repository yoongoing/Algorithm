#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cstring>

using namespace std;

int N;
int dy[4] = {0,0,-1,1};
int dx[4] = {-1,1,0,0};

int w_dy[4] = {-1,-1,1,1};
int w_dx[4] = {-1,1,-1,1};

int map[301][301];
int cnt[301][301];

typedef struct 
{
    int y;
    int x;
    int prev_dir;
}person;

bool check(int y, int x){
    if(y>=0 && x>=0 && y<N && x<N)
        return true;
    return false;
}
int prev_by_left(int prev, int next){
    if((prev==0) && (next==3))  return 3;
    if((prev==1) && (next==2))  return 0;
    if((prev==2) && (next==0))  return 2;
    if((prev==3) && (next==1))  return 1;
    return -1;
} 

int wall_by_left(int dir){
    if(dir == 0) return 3;
    if(dir == 1) return 2;
    if(dir == 2) return 0;
    if(dir == 3) return 1;
    return -1;
}
void bfs(int y, int x){
    queue<person> q;
    person p;
    p.y = y;
    p.x = x;
    p.prev_dir = -1;
    q.push(p);
    
    while(!q.empty()){
        int y = q.front().y;
        int x = q.front().x;
        int prev_dir = q.front().prev_dir;
        q.pop();

        cout<<y<<", "<<x<<endl;

        for(int i=0; i<4; i++){
            int next_dir = i;
            
            int ny = y + dy[next_dir];
            int nx = x + dx[next_dir];
            if(check(ny,nx) && map[ny][nx] != 1){
                if(prev_dir != next_dir){
                    int wall_dir = prev_by_left(prev_dir, next_dir);
                    if(wall_dir == -1) continue;
                    int wy = y + w_dy[wall_dir];
                    int wx = x + w_dx[wall_dir];

                    if(!check(wy,wx) || map[wy][wx] == 1){
                        if(cnt[ny][nx] != 987654321){
                            cnt[ny][nx] = min(cnt[ny][nx], cnt[y][x]+1);
                        }
                        else{
                            cnt[ny][nx] = cnt[y][x] + 1;
                        }
                        if((ny==N-1) && (nx==N-1))  continue;
                        p.y = ny;
                        p.x = nx;
                        p.prev_dir = next_dir;
                        q.push(p);
                    }
                }
                else{
                    int wall_dir = wall_by_left(next_dir);

                    int wy = y + dy[wall_dir];
                    int wx = x + dx[wall_dir];

                    if(!check(wy,wx) || map[wy][wx] == 1){
                        if(cnt[ny][nx] != 987654321){
                            cnt[ny][nx] = min(cnt[ny][nx], cnt[y][x]+1);
                        }
                        else{
                            cnt[ny][nx] = cnt[y][x] + 1;
                        }
                        if((ny==N-1) && (nx==N-1))  continue;

                        p.y = ny;
                        p.x = nx;
                        p.prev_dir = next_dir;
                        q.push(p);
                    }        
                }
            }
        } 
    }
}

int solution() {
    int answer = 0;

    memset(cnt, 987654321, sizeof(cnt));

    bfs(0,0);

    cout<<cnt[N-1][N-1];
    return answer;
}

int main(int argc, char const *argv[])
{
    cin>>N;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin>>map[i][j];

    int ans = solution();
    cout<<ans<<endl;
    return 0;
}





