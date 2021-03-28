#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> v[11];
int civil[11];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>N;
    for(int i=1; i<=N; i++)
        cin>>civil[i];
    
    for(int i=1; i<=N; i++){
        int n;
        cin>>n;
        for(int i=0; i<n; i++){
            int node;
            cin>>node;

            v[i].push_back(node);
        }
    }
    return 0;
}