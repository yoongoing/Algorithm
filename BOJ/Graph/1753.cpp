#include <iostream>
#include <queue>
#include <vector>

#define MAX 20000 + 2

using namespace std;

struct Gragh{
    int arrival;
    int weight;
};
struct cmp{
    bool operator()(Gragh a, Gragh b){
        return a.weight > b.weight;
    }
};

int V,E,K;
vector<Gragh> graph[MAX];
int dp[MAX];

void init(){
    for(int i=1; i<=V; i++)
        dp[i] = 987654321;
    dp[K] = 0;
}

void sol(int cur){
    priority_queue<Gragh, vector<Gragh>, cmp> pq;

    Gragh g;
    g.arrival = cur;
    g.weight  = 0;

    pq.push(g);

    // priority queue에 넣어가면서 안간곳중에 가장 작은곳 선택
    while(!pq.empty()){
        int next = pq.top().arrival;
        int weight = pq.top().weight;
        pq.pop();

        if(dp[next] < weight)
            continue;
        
        // neighbor 확인
        for(int j=0; j<graph[next].size(); j++){
            int neighbor = graph[next][j].arrival;
            int neighbor_weight = weight + graph[next][j].weight;

            
            // 업데이트 시
            if(neighbor_weight < dp[neighbor]){
                Gragh tmp;
                tmp.arrival = neighbor;
                tmp.weight = neighbor_weight;

                pq.push(tmp);
                dp[neighbor] = tmp.weight;
            }   
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>V>>E>>K;

    for(int i=0; i<E; i++){
        int u,v,w;
        cin>>u>>v>>w;
        
        Gragh tmp;
        tmp.arrival = v;
        tmp.weight = w;
        graph[u].push_back(tmp);
    }
    
    // dp INF로 초기화 & dp[K] = 0으로 초기화
    init();

    // solve
    sol(K);

    for(int i=1; i<=V; i++){
        if(dp[i] == 987654321)
            cout<<"INF\n";
        else
            cout<<dp[i]<<"\n";
    }
    return 0;
}