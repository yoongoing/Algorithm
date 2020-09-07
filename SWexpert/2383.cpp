#include <iostream>
#include <vector>
#include <math.h>
#include <queue>

using namespace std;

int n;
int map[10][10];

int p_map[10][10];  //현재 계단에 몇명의 사람이 있는지
int p_loc[10];      //사람별로 어떤 계단을 내려갈지 

int ptos[10];     //사람별로 계단에 가기위한 최소 시간

int ans = 987654321;

vector<pair<int, int> > person;
vector<pair<int, int> > stair;

int p_size;

void init_(){
    person.clear();
    stair.clear();
    ans = 987654321;
}

int cal(){
    int time = 0;
    int finish = 0;
    queue<int> q[2];

    for(int i=0; i<p_size; i++)
        ptos[i] = abs(person[i].first - stair[p_loc[i]].first) + abs(person[i].second - stair[p_loc[i]].second);
    

    while(true){
        if(finish == p_size)
            break;

        //분당 해당 계단에 사람 배치
        for(int i=0; i<p_size; i++){
            if(ptos[i] < 0)
                continue;

            if(ptos[i] == 0){
                if(q[p_loc[i]].size() < 3){
                    q[p_loc[i]].push(map[stair[p_loc[i]].first][stair[p_loc[i]].second]);
                    ptos[i] = -1;
                }
                continue;
            }
            ptos[i] -= 1;
        }
        
        //배치 후 계단내려가기
        for(int i=0; i<2; i++){
            int next = q[i].size();
            for(int j=0; j<next; j++){
                int temp = q[i].front();
                q[i].pop();
                if(temp > 1)
                    q[i].push(temp-1);
                else
                    finish++;
            }
        }
        time++;
    }
    return time + 1; 
}
void dfs(int cnt){
    if(cnt == p_size){
        ans = min(ans,cal());
        return;
    }
    for(int i=0; i<2; i++){
        p_loc[cnt] = i;
        dfs(cnt+1);
    }
}

// void dfs(int cnt){
//     if(cnt == p_size){
//         ans = min(ans, cal());
//         return;
//     }

//     p_loc[cnt] = 0;
//     dfs(cnt+1);

//     p_loc[cnt] = 1;
//     dfs(cnt+1);
    
//     return;
// }

int main(){
    int test_case;
    cin>>test_case;
    for(int T=1; T<=test_case; T++){
        cin>>n;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin>>map[i][j];
                if(map[i][j] == 1)
                    person.push_back(make_pair(i,j));
                if(map[i][j] > 1)
                    stair.push_back(make_pair(i,j));
            }
        }
        p_size = person.size();
        dfs(0);
        cout<<"#"<<T<<" "<<ans<<endl;
        init_();
    }
    
    return 0;
}