#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int N,M,T;
int arr[51][51];
int visited[51][51] = {0,};

int dy[4] = {0,0,-1,1};
int dx[4] = {-1,1,0,0};

int check(int y, int x){
    return y>=1 && x>=1 && y<=N && x<=M;
}

void print(){
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++)
            cout<<arr[i][j]<<" ";
        cout<<"\n";
    }
    cout<<"\n";

}

double cal(){
    double sum = 0;
    double cnt = 0;

    for(int i=1; i<=N; i++)
        for(int j=1; j<=M; j++)
            if(arr[i][j] > 0){
                sum += arr[i][j];
                cnt++;
            }
                
    return sum/cnt;
}

void rotate(int n, int dir){
    if(dir == 0){
        int temp = arr[n][M];
        for(int i=M; i>=1; i--)
            arr[n][i] = arr[n][i-1];
        arr[n][1] = temp;
    }
    else if(dir == 1){
        int temp = arr[n][1];
        for(int i=0; i<=M; i++)
            arr[n][i] = arr[n][i+1];
        arr[n][M] = temp;
    }
}

int bfs(int y, int x){
    queue<pair<int, int> > q;
    int temp[51][51] = {0,};

    q.push(make_pair(y, x));
    visited[y][x] = 1;

    int cnt = 1;
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        int n = arr[y][x];
        q.pop();

        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(nx > M)
                nx = 1;
            if(nx < 1)
                nx = M;
            
            if(check(ny, nx)){
                int idx = arr[ny][nx];

                // 가본적 없고, 같은 수며, 0이 아닐때
                if(!visited[ny][nx] && n==idx){

                    temp[ny][nx] = 1;
                    visited[ny][nx] = 1;
                    q.push(make_pair(ny, nx));
                    cnt++;
                }
            }
        }
    }

    for(int i=1; i<=N; i++)
        for(int j=1; j<=M; j++)
            if(temp[i][j])
                arr[i][j] = 0;
    
    if(cnt != 1){
        arr[y][x] = 0;
        return 1;
    }
        
    return 0;
}

int count(int cnt){
    for(int i=1; i<=N; i++)
        for(int j=1; j<=M; j++)
            if(arr[i][j] > 0)
                cnt += arr[i][j];
    return cnt;
}

int main(void){
    cin>>N>>M>>T;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0; i<T; i++){
        int x,d,k;
        cin>>x>>d>>k;

        for(int j=x; j<=N; j+=x){
            for(int t=0; t<k; t++)
                rotate(j, d);
        }

        memset(visited, 0, sizeof(visited));
        int flag = 0;
        for(int i=1; i<=N; i++){
            for(int j=1; j<=M; j++){
                if(!visited[i][j] && arr[i][j]>0){
                    int result = bfs(i, j);
                    if(result)
                        flag = 1;
                } 
            }
        }
        if(!flag){
            double stan = cal();
            for(int i=1; i<=N; i++){
                for(int j=1; j<=M; j++){
                    if(arr[i][j] == 0)
                        continue;
                    if(arr[i][j] > stan)
                        arr[i][j]--;
                    else if(arr[i][j] < stan)
                        arr[i][j]++;
                }
            }
        }
    }
    cout<<count(0)<<"\n";
    return 0;
}