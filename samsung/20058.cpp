#include <iostream>
#include <queue>

using namespace std;

int N,Q;
int binary[7] = {1, 2, 4, 8, 16, 32, 64};
int A[65][65];
int L[1001];
int visited[65][65] = {0,};

int check(int y, int x){
    return y>=0 && x>=0 && y<binary[N] && x<binary[N];
}

void print(){
    for(int i=0; i<binary[N]; i++){
        for(int j=0; j<binary[N]; j++)
            cout<<A[i][j]<<" ";
        cout<<"\n";
    }
}

int sum(int s){
    for(int i=0; i<binary[N]; i++)
        for(int j=0; j<binary[N]; j++)
            s += A[i][j];
    return s;
}

void shift(int n){
    int idx = 0;
    int temp[65][65];
    int term = binary[n - 1];

    // 2^n x 2^n
    for(int i=0; i<binary[N]; i+=binary[n]){
        for(int j=0; j<binary[N]; j+=binary[n]){
            int dir = 0;
            
            for(int y=0; y<binary[n]; y++){
                for(int x=0; x<binary[n]; x++){
                    temp[x+i][binary[n]-1-y+j] = A[y+i][x+j];
                }
            }
        }
    }

    for(int i=0; i<binary[N]; i++){
        for(int j=0; j<binary[N]; j++){
            A[i][j] = temp[i][j];
        }
    }
}

void melt(){
    int copy_A[65][65] = {0,};


    for(int i=0; i<binary[N]; i++){
        for(int j=0; j<binary[N]; j++){
            int cnt = 0;

            for(int dir=0; dir<4; dir++){
                int ny = i + dy[dir];
                int nx = j + dx[dir];
                
                if(A[ny][nx] == 0)
                    continue;
                if(check(ny, nx) && A[ny][nx]>0){
                    cnt++;
                }
            }

            if(cnt < 3)
                copy_A[i][j] = 1;
        }
    }

    for(int i=0; i<binary[N]; i++){
        for(int j=0; j<binary[N]; j++){
            if(copy_A[i][j] && A[i][j] > 0)
                A[i][j]--;
        }
    }
}

int bfs(int y, int x){
    int cnt = 1;
    queue<pair<int, int> > q;

    q.push(make_pair(y,x));
    visited[y][x] = 1;

    while(!q.empty()){
        y = q.front().first;
        x = q.front().second;
        q.pop();

        for(int dir=0; dir<4; dir++){
            int ny = y + dy[dir];
            int nx = x + dx[dir];

            if(check(ny, nx) && !visited[ny][nx] && A[ny][nx]!=0){
                q.push(make_pair(ny,nx));
                visited[ny][nx] = 1;
                cnt++;
            }
        }
    }
    return cnt;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>N>>Q;
    for(int i=0; i<binary[N]; i++){
        for(int j=0; j<binary[N]; j++){
            cin>>A[i][j];
        }
    }

    for(int i=0; i<Q; i++){
        cin>>L[i];
        shift(L[i]);
        melt();
    }

    cout<<sum(0)<<"\n";

    int land = 0;
    for(int i=0; i<binary[N]; i++){
        for(int j=0; j<binary[N]; j++){
            if(!visited[i][j] && A[i][j]!=0){
                land = max(land, bfs(i,j));
            }
        }
    }
    cout<<land<<"\n";

    return 0;
}