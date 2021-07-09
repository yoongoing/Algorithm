#include <iostream>
#include <vector>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N,M;
    cin>>N>>M;

    long long int P[1001];
    long long int sum[1001] = {0,};
    for(int i=0; i<M; i++)
        cin>>P[i];
    for(int i=0; i<M-1; i++){
        int a = min(P[i], P[i+1]);
        int b = max(P[i], P[i+1]);
        sum[a]++;
        sum[b]--;
    }

    for(int i=1; i<=N; i++)
        sum[i] += sum[i-1];

    long long int ans = 0;
    for(int i=1; i<N; i++){
        int a,b,c;
        cin>>a>>b>>c;
        
        if(sum[i] != 0)
            ans += min(a*sum[i], b*sum[i]+c);
    }
    cout<<ans<<"\n";

    return 0;
}