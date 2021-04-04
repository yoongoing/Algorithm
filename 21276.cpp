#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

int N,M;
int indegree[1005];
vector<string> name;
map<string, int> idx;
vector<vector<int> > G(1005);
vector<vector<int> > children(1005);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>N;
    for(int i=0; i<N; i++){
        string str;
        cin>>str;
        name.push_back(str);
    }

    sort(name.begin(), name.end());
    for(int i=0; i<N; i++)
        idx[name[i]] = i;
    

    cin>>M;
    for(int i=0; i<M; i++){
        string from, to;
        cin>>from>>to;
        int f = idx[from];
        int t = idx[to];

        G[t].push_back(f);
        indegree[f]++;
    }

    queue<int> q;
    vector<int> super_father;
    for(int i=0; i<N; i++){
        if(indegree[i] == 0){
            super_father.push_back(i);
            q.push(i);
        }
    }

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        for(int next : G[cur]){
            indegree[next]--;
            if(indegree[next] == 0){
                children[cur].push_back(next);
                q.push(next);
            }
        }
    }

    cout<<super_father.size()<<"\n";
    for(int i : super_father)
        cout<<name[i]<<" ";
    cout<<"\n";
    for(int i=0; i<N; i++){
        cout<<name[i]<<' '<<children[i].size()<<" ";
        sort(children[i].begin(), children[i].end());

        for(int j : children[i])
            cout<<name[j]<<" ";
        cout<<"\n";
    }
    return 0;
}