#include <iostream>

using namespace std;

int D[1001][1001];

long combination(int N, int K){
    if(K==0 || N==K)
        return 1;
    return combination(N-1, K-1) + combination(N-1, K); 
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N,K;
    cin>>N>>K;

    // long result = combination(N,K);
    int result;

    for(int n=1; n<=N; n++){
        for(int k=0; k<=n; k++){
            if(n==k || k==0)
                D[n][k] = 1;
            else
                D[n][k] = (D[n-1][k-1] + D[n-1][k]) % 10007;
        }
    }

    cout<<D[N][K]<<"\n";
    return 0;
}