#include <iostream>
#include <vector>

using namespace std;

int N,M;
long long k;
int A[10010];
//vector<int> friend[10001];
int root[10010];
int check[10010] = {0,};

long long my_min(long long a, long long b){
    if(a < b)
        return a;
    return b;
}

int find(int n){
    if(root[n] < 0)
        return n;
    
    return root[n] = find(root[n]);
}

void my_union(int a, int b){
    a = find(a);
    b = find(b);

    if(a == b)
        return;
    if(A[a] < A[b])
        root[b] = a;
    else
        root[a] = b;
}


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>N>>M>>k;
    for(int i=1; i<=N; i++){
        cin>>A[i];
        root[i] = -1;
    }
        
    for(int i=0; i<M; i++){
        int v,w;
        cin>>v>>w;
        my_union(v, w);
    }

    long long ans = 0;
    for(int i=1; i<=N; i++)
        if(root[i] == -1)
            ans += A[i];
    
    if(k < ans)
        cout<<"Oh no\n";
    else
        cout<<ans<<"\n";

    return 0;
}