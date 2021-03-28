#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N;
vector<int> v[11];
int civil[11];
int devide[11];
int visited[11] = {0,};
int ans = 987654321;

int search(int idx, int type, int cost){
    int cnt = 1;
    visited[idx] = 1;

    for(int j=0; j<v[idx].size(); j++){
        
        if(type==devide[v[idx][j]] && !visited[v[idx][j]]){
            cnt += search(v[idx][j], type, cost+civil[v[idx][j]]);
        }
    }
    return cnt;
}

int cal(int cnt){
    int sec0 = N - cnt;
    int sec1 = cnt;

    int idx0, sum0 = 0;
    int idx1, sum1 = 0;
    for(int i=1; i<=N; i++){
        if(devide[i]){ // 1구역이라면
            idx1 = i;
            sum1 += civil[i];
        }    
        else{ // 0구역이라면
            idx0 = i;
            sum0 += civil[i];
        } 
    }
    // cout<<sum1<<" "<<sum0<<"\n";
    memset(visited, 0, sizeof(visited));
    int cnt0 = search(idx0, 0, 0);
    memset(visited, 0, sizeof(visited));
    int cnt1 = search(idx1, 1, 0);

    if(cnt0!=sec0 || cnt1!=sec1)
        return -1;

    return abs(sum0 - sum1);
}


void dfs(int idx){
    if(idx == N+1){
        int cnt = 0;
        for(int i=1; i<=N; i++)
            if(devide[i])
                cnt++;
        if(cnt==0 || cnt==N)
            return; // 하나로만 고르는 경우는 제외
        
        int diff = cal(cnt);
        // cout<<diff<<"\n";
        if(diff != -1)
            ans = min(ans, diff);
        
        return;
    }

    devide[idx] = 1;
    dfs(idx + 1);

    devide[idx] = 0;
    dfs(idx + 1);
}


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>N;
    for(int i=1; i<=N; i++)
        cin>>civil[i];
    
    for(int i=1; i<=N; i++){
        int n;
        cin>>n;
        for(int j=0; j<n; j++){
            int node;
            cin>>node;
            v[i].push_back(node);
        }
    }

    dfs(1);

    if(ans == 987654321)
        cout<<"-1\n";
    else
        cout<<ans<<"\n";
    return 0;
}