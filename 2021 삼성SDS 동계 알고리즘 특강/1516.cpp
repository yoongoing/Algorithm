#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin>>N;

    int check[501] = {0,};
    int time[501] = {0,};
    int result[501] = {0,};
    vector<int> v[501];

    for(int i=1; i<=N; i++){
        cin>>time[i];
        while(1){
            int node;
            cin>>node;
            if(node == -1)
                break;
            
            check[i]++;
            v[node].push_back(i);
        }
    }

    queue<int> q;
    for(int i=1; i<=N; i++){
        if(!check[i]){
            q.push(i);
        }
            
    }

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(int i=0; i<v[node].size(); i++){
            int nextnode = v[node][i];

            result[nextnode] = max(result[nextnode], result[node] + time[node]);
            check[nextnode]--;

            if(!check[nextnode])
                q.push(nextnode);
        }
    }

    for(int i=1; i<=N; i++)
        cout<<result[i] + time[i]<<"\n";

    return 0;
}