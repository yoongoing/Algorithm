#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct cmp{
    bool operator(vector<int, pair<int, int> > a, <int, pair<int, int> > b){
        return a.first > b.second;
    }
};

int N,M;
int school[1010];
priority_queue<pair<int, pair<int,int> >, vector<int, pair<int,int >, cmp> pq;  
int road[1010][1010] = {0,};
int root[1010];

int find(int n){
    if(root[n] == n)
        return n;
    return root[n] = find(n);
}

void Union(int a, int b){
    a = find(a);
    b = find(b);

    root[b] = a;
}

void sol(){
    for(int i=1; i<=N; i++){
        for(int j=i+1; j<=N; j++){
            if(road[i][j] != 0){

            }
        }
    }
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
        
        pq.push(make_pair(d,make_pair(u,v)));
    }

    return 0;
}