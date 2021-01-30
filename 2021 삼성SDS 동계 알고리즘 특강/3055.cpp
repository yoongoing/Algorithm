#include <iostream>
#include <string>
#include <queue>
#include <cstring>

using namespace std;

int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
int R,C;

pair<int, int> start, finish;
queue<pair<int, int> > W;

string map[51];
int chk[51][51];

int BFS(void){
    memset(chk, -1, sizeof(chk));
    queue<pair<int, int> > mole;
    mole.push(start);
    chk[start.first][start.second] = 0;

    while (!mole.empty()){
        int Wsize = W.size();

        //우선 물이 차오른다
        for (int j=0; j<Wsize; j++){
            int y = W.front().first;
            int x = W.front().second;
            W.pop();

            for (int k=0; k<4; k++){
                int ny = y + dy[k];
                int nx = x + dx[k];
                
                if((ny<0) || (nx<0) || (ny>=R) || (nx>=C))
                    continue;
    
                //물은 빈칸으로 흐름
                if (map[ny][nx]=='.'){
                    map[ny][nx] = '*';
                    W.push(make_pair(ny, nx));
                }
            }
        }

        int Msize = mole.size();
        for (int i=0; i<Msize; i++){
            int y = mole.front().first;
            int x = mole.front().second;
            mole.pop();

            //목적지 도달 시
            if (y==finish.first && x==finish.second)
                return chk[y][x];

            //두더지가 움직일 차례
            for (int j=0; j<4; j++){
                int ny = y + dy[j];
                int nx = x + dx[j];
                
                if((ny<0) || (nx<0) || (ny>=R) || (nx>=C))
                    continue;

                //돌과 물에 차 있는 곳으로 움직일 수 없다
                if (map[ny][nx] != '*' && map[ny][nx]!='X' && chk[ny][nx]==-1){
                    chk[ny][nx] = chk[y][x] + 1;
                    mole.push(make_pair(ny, nx));
                }
            }
        }
    }
    return -1;
}

int main(void){
    int result;
    cin>>R>>C;

    for (int i=0; i<R; i++){
        cin >> map[i];
        for (int j = 0; j < C; j++){
            if (map[i][j] == 'S')
                start = make_pair(i, j);

            else if (map[i][j] == '*')
                W.push(make_pair(i, j));

            else if (map[i][j] == 'D')
                finish = make_pair(i, j);
        }   
    }
    result = BFS();

    if (result == -1)
        cout<<"KAKTUS\n";
    else
        cout<<result<<"\n";
        
    return 0;
}