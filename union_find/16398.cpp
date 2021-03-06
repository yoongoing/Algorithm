#include <iostream>
#include <queue>

using namespace std;

struct Info{
    int from,to;
    long long cost;
};

struct cmp{
    bool operator()(Info a, Info b){
        return a.cost > b.cost;
    }
};

int N;
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

long long sol(long long sum){
    while(!pq.empty()){
        
        int from = pq.top().from;
        int to = pq.top().to;
        long long cost = pq.top().cost;

        if(!compare(from, to)){
            sum += cost;
            Union(from, to);
        }
        pq.pop();
    }
    return sum;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>N;

    for(int i=1; i<=N; i++)
        root[i] = i;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            long long cost;
            cin>>cost;

            if(i < j){
                Info tmp = {i, j, cost};
                pq.push(tmp);
            }
        }
    }

    cout<<sol(0)<<"\n";
}