#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N;
vector<pair<int,int> > v[100001];
int visited[100001];
long long ans = -1;
int node;

void dfs(int idx, long long cost){
    if(visited[idx])
        return;
    
    visited[idx] = 1;

    if(cost > ans){
        ans = cost;
        node = idx;
    }
    
    for(int j=0; j<v[idx].size(); j++)
        dfs(v[idx][j].first, cost+v[idx][j].second);
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>N;
    for(int i=0; i<N; i++){
        int from;
        cin>>from;

        int to, cost;
        while(1){
            cin>>to;
            if(to == -1)
                break;
            cin>>cost;

            v[from].push_back(make_pair(to, cost));
        }
    }

    dfs(1, 0);
    memset(visited, 0, sizeof(visited));
    ans = 0;
    dfs(node, 0);
    
    cout<<ans<<"\n";
    return 0;
}