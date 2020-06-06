#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
int N,M,L;
int map[50][50];
pair<int, int> hole;

int dy[4] = {0,0,-1,1};
int dx[4] = {-1,1,0,0};
int dir[4];

void chk_dir(int type){
    if(type == 1)       dir[0] = dir[1] = dir[2] = dir[3] = 1;
    else if(type == 2)  dir[2] = dir[3] = 1;
    else if(type == 3)  dir[0] = dir[1] = 1;
    else if(type == 4)  dir[1] = dir[2] = 1;
    else if(type == 5)  dir[1] = dir[3] = 1;
    else if(type == 6)  dir[0] = dir[3] = 1;
    else if(type == 7)  dir[0] = dir[2] = 1;
}

bool chk_nextdir(int dir, int next_type){
    if(dir==0 && (next_type==1 || next_type==3 || next_type==4 || next_type==5))
        return true;
    if(dir==1 && (next_type==1 || next_type==3 || next_type==6 || next_type==7))
        return true;
    if(dir==2 && (next_type==1 || next_type==2 || next_type==5 || next_type==6))
        return true;
    if(dir==3 && (next_type==1 || next_type==2 || next_type==4 || next_type==7))
        return true;
    return false;
}

bool check(int y, int x){
    if(y<0 || x<0 || y>=N || y>=N)
        return true;
    return false;
}

int bfs(int y, int x){
    int ans = 1;
    
    int chk[50][50] = {0,};
    chk[y][x] = 1;

    queue <pair<int, int> > q;
    q.push(make_pair(y,x));

    for(int k=1; k<L; k++){
        int size = q.size();
        for(int i=0; i<size; i++){
            memset(dir,0,sizeof(dir));
            
            y = q.front().first;
            x = q.front().second;
            q.pop();

            chk_dir(map[y][x]);

            for(int i=0; i<4; i++){
                if(!dir[i])
                    continue;

                int ny,nx;
                ny = y + dy[i];
                nx = x + dx[i];

                if(check(ny,nx))
                    continue;

                if(!chk_nextdir(i,map[ny][nx]))
                    continue;

                if(chk[ny][nx]==0 && map[ny][nx]>0){
                    q.push(make_pair(ny,nx));
                    chk[ny][nx] = 1;
                    ans++;
                } 
            }    
        }
    }
    return ans;
}

int main(int argc, char** argv){
    int test_case;
    cin>>test_case;
    for(int T=1; T<=test_case; T++){
        memset(map,0,sizeof(map));
        cin>>N>>M>>hole.first>>hole.second>>L;
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                cin>>map[i][j];
            }
        }
        cout<<"#"<<T<<" "<<bfs(hole.first,hole.second)<<endl;
    }
    return 0;
}
