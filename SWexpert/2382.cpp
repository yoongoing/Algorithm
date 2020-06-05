#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <deque>

using namespace std;

typedef struct 
{
    int y;
    int x;
    unsigned int num;
    int dir;
}MICRO;

bool cmp(const MICRO &m1, const MICRO &m2)
{
	return m1.num > m2.num;
}

deque<MICRO> dq;

int N,M,K;
unsigned int cell[101][101];
int dir_cell[101][101];

int dy[4] = {-1,1, 0,0};
int dx[4] = { 0,0,-1,1};

void init_(){
    dq.clear();
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++){
            cell[i][j] = 0;
            dir_cell[i][j] = 0;
        }
}

bool check(int y, int x){
    if(y==0 || x==0 || y==N-1 || x==N-1)
        return true;
    return false;
}

int conv_dir(int dir){
    int conv;

    if(dir == 1)        conv = 2;
    else if(dir == 2)   conv = 1;
    else if(dir == 3)   conv = 4;
    else if(dir == 4)   conv = 3;

    return conv;
}


int sol(){
    for(int k=1; k<=M; k++){
        int size = dq.size();

        //미생물 군집 이동
        for(int i=0; i<size; i++){
            int y = dq.front().y;
            int x = dq.front().x;
            unsigned int num = dq.front().num;
            int dir = dq.front().dir;
            dq.pop_front();

            cell[y][x] = 0;
            dir_cell[y][x] = 0;

            if(num == 0)
                continue;
            
            int ny = y + dy[dir - 1];
            int nx = x + dx[dir - 1];
            

            //끝에 닿았을경우
            if(check(ny,nx)){
                dir = conv_dir(dir);
                num /= 2;    
            }

            MICRO micro;
            micro.y = ny;
            micro.x = nx;
            micro.num = num;
            micro.dir = dir;

            dq.push_back(micro);
        }
        //미생물 합쳐주기
        for(int i=0; i<size; i++){
            int y = dq.front().y;
            int x = dq.front().x;
            unsigned int num = dq.front().num;
            int dir = dq.front().dir;
            dq.pop_front();

            
            if(cell[y][x] == 0){
                cell[y][x] = num;
                dir_cell[y][x] = dir;
                
            }
            //여러 미생물이 있을경우
            else{
                int prev = cell[y][x];
                unsigned int next_num = num + cell[y][x];
                int vs = max(cell[y][x], num);
                cell[y][x] = next_num;
                if(prev != vs)
                    dir_cell[y][x] = dir;
            }
            
        }
        //큐에 다시 넣어주기
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(cell[i][j] > 0){
                    MICRO micro;
                    micro.y = i;
                    micro.x = j;
                    micro.num = cell[i][j];
                    micro.dir = dir_cell[i][j];
                    dq.push_back(micro);
                }    
            }
        }
    }

    int ans = 0;
    while(!dq.empty()){
        ans += dq.front().num;
        dq.pop_front();
    }

    return ans;
}

int main(int argc, char** argv){
    int test_case;
    cin>>test_case;
    for(int T=1; T<=test_case; T++){
        cin>>N>>M>>K;
        for(int i=0; i<K; i++){
            MICRO micro;
            cin>>micro.y>>micro.x>>micro.num>>micro.dir;
            dq.push_back(micro);
            cell[micro.y][micro.x] = micro.num;
            dir_cell[micro.y][micro.x] = micro.dir;
        }
        sort(dq.begin(),dq.end(),cmp);
        cout<<"#"<<T<<" "<<sol()<<endl;
        init_();
    }
    return 0;
}