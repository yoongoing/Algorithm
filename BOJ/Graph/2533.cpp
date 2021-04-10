#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N;
vector<int> social[1000000 + 1];
vector<int> F[1000000 + 1];

int visited[1000000 + 1] = {0,};
int cache[1000000 + 1][2];

int my_min(int a, int b){
    if(a < b)
        return a;
    return b;
}

void maker(int node){
    visited[node] = 1;

    for(int i=0; i<social[node].size(); i++){
        if(!visited[social[node][i]]){
            F[node].push_back(social[node][i]);
            maker(social[node][i]);
        }
    }
}

int sol(int idx, int isEarly){
    int &ret = cache[idx][isEarly];

    if(ret != -1)
        return ret;
    
    if(isEarly){
        ret = 1;
        for(int i=0; i<F[idx].size(); i++){
            ret += my_min(sol(F[idx][i], 1) , sol(F[idx][i], 0));
        }
    }
    else{
        ret = 0;
        for(int i=0; i<F[idx].size(); i++){
            ret += sol(F[idx][i], 1);
        }
    }
    return ret;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>N;

    for(int i=0; i<N-1; i++){
        int u, v;
        cin>>u>>v;
        social[u].push_back(v);
        social[v].push_back(u);
    }

    memset(cache, -1, sizeof(cache));

    maker(1);

    cout<<my_min(sol(1,0) , sol(1,1))<<"\n";
    return 0;
}