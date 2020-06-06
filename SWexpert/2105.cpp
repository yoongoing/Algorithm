#include <iostream>
#include <cstring>

using namespace std;

int N;
int map[20][20];
int chk[20][20];
int dessert[101];
int ans;

pair<int, int> start;

int dy[4] = {1,1,-1,-1};
int dx[4] = {1,-1,-1,1};


bool check(int y, int x){
    if((y>=0) && (x>=0) && (y<N) && (x<N))
        return true;
    return false;
}

void dfs(int y, int x, int prev, int cnt){
    if((cnt>1) && (start.first==y) && (start.second==x)){
        ans = max(ans, cnt);
        return;
    }
    chk[y][x] = 1;
    dessert[map[y][x]] = 1;

    for(int i=0; i<2; i++){
        int ny = y + dy[prev + i];
        int nx = x + dx[prev + i];    
        

        if(check(ny,nx) && chk[ny][nx]==0 && dessert[map[ny][nx]]==0){
            dfs(ny,nx,prev+i,cnt+1);
        }
            
        else if(start.first==ny && start.second==nx)
            dfs(ny,nx,prev+i,cnt+1);
    }
    chk[y][x] = 0;
    dessert[map[y][x]] = 0;
}

int main(int argc, char** argv){
    int test_case;
    cin>>test_case;
    for(int T=1; T<=test_case; T++){
        ans = -1;
        memset(dessert, 0, sizeof(dessert));
        
        cin>>N;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cin>>map[i][j];
                chk[i][j] = 0;
            }
        }
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                start.first = i;
                start.second = j;
                dfs(i,j,0,0);
            }
        }
        cout<<"#"<<T<<" "<<ans<<endl;
    }
    return 0;
}