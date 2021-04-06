#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Info{
    int from,to,cost;
};

struct cmp{
    bool operator()(Info a, Info b){
        return a.cost > b.cost;
    }
};

int N,M;
char school[1010];
int root[1010];
priority_queue<Info, vector<Info>, cmp> pq;  

int find(int n){
    if(root[n] == n)
        return n;
    return root[n] = find(root[n]);
}

void Union(int a, int b){
    a = find(a);
    b = find(b);

    if(a == b)
        return;
    root[b] = a;
}

int compare(int a, int b){
    a = find(a);
    b = find(b);
    
    if(a == b)
        return 1;
    return 0;
}

int sol(int sum){
    while(!pq.empty()){
        int from = pq.top().from;
        int to = pq.top().to;
        int cost = pq.top().cost;

        // 학교의 성별이 다르고, 가보지 않은곳 == 루트가 같은곳
        if(!compare(from, to) && (school[from]!=school[to])){
            Union(from, to);
            sum += cost;
        }
        pq.pop();
    }
    return sum;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>N>>M;
    for(int i=1; i<=N; i++){
        cin>>school[i];
        root[i] = i;
    }

    for(int i=0; i<M; i++){
        int u,v,d;
        cin>>u>>v>>d;
        Info tmp = {u,v,d};
        pq.push(tmp);
    }

    int result = sol(0);
    
    for(int i=2; i<=N; i++){
        if(!compare(1, i)){
            cout<<"-1\n";
            return 0;
        }
            
    }
    cout<<result<<"\n";
    return 0;
}