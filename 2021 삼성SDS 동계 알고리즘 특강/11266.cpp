#include <iostream>
#include <vector>

using namespace std;

int V,E;
int num = 1;
int cnt = 0;
vector<int> adj[10010];
bool ans[10010]; // 단절점이면 true
int visit[10010] = {0,};

// 예외 : 루트의 경우
// 나의 방문순서와 자식들이 만나는 방문순서중 가장 작은 값을 비교.
int dfs(int parent, int cur, bool isRoot){
    int min_visit = num; //내 자식들이 만날수 있는 점중에서 가장 작은 점
    int children = 0;

    // 체크인
    visit[cur] = num++; // 나(=cur)의 번호

    for(int i=0; i<adj[cur].size(); i++){
        int next = adj[cur][i];
        
        if(next == parent)
            continue;

        if(visit[next]){ // 방문한적이 있는 노드라면
            min_visit = min(min_visit, visit[next]);
            continue; // 안감
        }

        int next_value = dfs(cur, next, 0);
        min_visit = min(min_visit, next_value);
        
        if(!isRoot && next_value >= visit[cur]){
            ans[cur] = true; // 단절점     
        }
        children++;
    }

    if(adj[cur].size() == 1)
        return visit[cur];

    if(isRoot){
        // 자식이 두개이상이면 단절점
        if(children >= 2)
            ans[cur] = true;
    }
    // 체크아웃
    return min(visit[cur], min_visit); // 내가 만난 점중에서 방문순서가 가장 낮은점을 반환함.
}



int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>V>>E;
    for(int i=0; i<E; i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // 단절점을 찾고
    for(int i=1; i<=V; i++){
        if(visit[i] == 0)
            int total = dfs(0, i, 1);
    }

    // 개수 출력
    for(int i=1; i<=V; i++)
        if(ans[i])
            cnt++;
    cout<<cnt<<"\n";

    // 노드
    for(int i=1; i<=V; i++){
        if(ans[i])
            cout<<i<<" ";
    }
    return 0;
}