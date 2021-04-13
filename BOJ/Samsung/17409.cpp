#include <iostream>
#include <vector>

using namespace std;

struct Info{
    int r,c,s;
};

int N,M,K;
int ans = 987654321;
int map[51][51];
int copy_map[51][51];
int temp[51][51];

vector<Info> info;
vector<int> order;
int visited[7];

// 오 아 왼 위
int dy[4] = {0,1,0,-1}; 
int dx[4] = {1,0,-1,0};

int check(int y, int x, int k){
    if((y+k>=1) &&(x+k>=1) && (y+k<=N) && (x+k<=M))
        return 1;
    return 0;
}

void cal(){
    int result = 987654321;
    for(int i=1; i<=N; i++){
        int sum = 0;
        for(int j=1; j<=M; j++)
            sum += copy_map[i][j];

        result = min(result, sum);    
    }
    ans = min(ans, result);
}

void copy(int r, int c, int s){
    for(int i=r-s; i<=r+s; i++){
        for(int j=c-s; j<=c+s; j++){
            if(i==r && j==c)
                continue;
            copy_map[i][j] = temp[i][j];
        }
    }
}

void cpy_map(){
    for(int i=1; i<=N; i++)
        for(int j=1; j<=M; j++)
            copy_map[i][j] = map[i][j];
    
}

void shift(int r, int c, int s){

    for(int k=0; k<s; k++){
        int y = r - s + k;
        int x = c - s + k;

        for(int i=0; i<4; i++){
            
            while(1){
                int ny = y + dy[i];
                int nx = x + dx[i];

                if(ny>r+s-k || nx>c+s-k || ny<r-s+k || nx<c-s+k)
                    break;

                temp[ny][nx] = copy_map[y][x];
                y = ny;
                x = nx;
            }
        }
    }
    copy(r, c, s);
}

void dfs(int cnt){
    if(cnt == K){
        cpy_map();
        for(int i=0; i<order.size(); i++){
            shift(info[order[i]].r, info[order[i]].c, info[order[i]].s);
        }
        cal();
        return;
    }
    
    for(int i=0; i<K; i++){
        if(!visited[i]){
            order.push_back(i);
            visited[i] = 1;

            dfs(cnt+1);
            
            order.pop_back();
            visited[i] = 0;
        }
        
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>N>>M>>K;
    for(int i=1; i<=N; i++)
        for(int j=1; j<=M; j++)
            cin>>map[i][j];
        
    for(int i=0; i<K; i++){
        int r, c ,s;
        cin>>r>>c>>s;

        Info tmp = {r,c,s};
        info.push_back(tmp);
    }
    dfs(0);
    cout<<ans<<"\n";

    return 0;
}