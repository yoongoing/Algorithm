#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N,M;
int indegree[40000];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>N>>M;

    vector<int> v [32001];
    for(int i=0; i<M; i++){
        int first, second;
        cin>>first>>second;

        v[first].push_back(second);
        indegree[second]++;
    }

    queue<int> q;
    
    for(int i=1; i<=N; i++){
        if(!indegree[i])
            q.push(i);
    }

    while(!q.empty()){
        int cur = q.front();
        cout<<cur<<" ";
        q.pop();

        for(int i=0; i<v[cur].size(); i++){
            indegree[v[cur][i]]--;
            if(!indegree[v[cur][i]])
                q.push(v[cur][i]);
        }
    }
    cout<<"\n";
}