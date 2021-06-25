#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 987654321

int N,M;
vector<pair<int, int> > V[101];
long long dist[101];

vector<int> R[101];
int previous[101];
int visited[101] = {0,};

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>N>>M;
    for(int i=1; i<=M; i++){
        int u,v,w;
        cin>>u>>v>>w;
        V[u].push_back(make_pair(v, (w*-1)));
        R[v].push_back(u);
    }

    queue<int> q;
    q.push(N);
    visited[N] = 1;
    while(!q.empty()){
        int ridx = q.front();
        q.pop();

        for(auto next : R[ridx]){

            if(!visited[next]){
                visited[next] = true;
                q.push(next);
            }
        }
    }


    bool cycle = false;
    for(int i=1; i<=N; i++)
        dist[i] = INF;
    
    dist[1] = 0;

    for(int k=1; k<=N; k++){
        
        for(int i=1; i<=N; i++){    
            int from = i;
            for(auto &n : V[i]){
                int to = n.first;
                int cost = n.second;

                if(dist[from]!=INF && dist[to]>dist[from]+cost){
                    dist[to] = dist[from] + cost;
                    previous[to] = from;
                    
                    if(k==N && visited[to])
                        cycle = true;
                }
            }
        }
    }

    if(cycle){
        cout<<"-1\n";
        return 0;
    }
    
    vector<int> ans;
    int idx = N;
    while(1){
        ans.push_back(idx);
        if(idx == 1)
            break;
        else
            idx = previous[idx];
    }
    for(int i=ans.size()-1; i>=0; i--)
        cout<<ans[i]<<" ";
    cout<<"\n";
        
    return 0;
}