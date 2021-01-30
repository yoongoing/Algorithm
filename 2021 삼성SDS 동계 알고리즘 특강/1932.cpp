#include <iostream>

using namespace std;

int N;
int map[503][503] = {0,};
int dp[503][503];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>N;

    for (int i=1; i<=N; i++){
        for(int j=1; j<=i; j++){
            cin>>map[i][j];
        }
    }
    
    dp[1][1] = map[1][1];
    for(int i=2; i<=N; i++){
        for(int j=1; j<=i; j++){
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + map[i][j];
        }
    }

    int ans = -1;
    for(int i=1; i<=N; i++){
        ans = max(ans, dp[N][i]);
    }
    cout<<ans<<"\n";

    return 0;
}