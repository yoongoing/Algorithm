#include <iostream>
#include <string>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m;
    int a[1010][1010] = {0,};
    int dp[1010][1010] = {0,}; // [i][j]를 오른쪽 아래로 했을때 가장 큰 정사각형 
    
    cin>>n>>m;

    for(int i=1; i<=n; i++){
        string str;
        cin>>str;

        for(int j=0; j<=str.size(); j++){
            a[i][j+1] = str[j] - '0';
        }
    }

    int ans = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(a[i][j] != 0){
                // 조사를 해야하는데 이웃한 곳들 : 왼쪽, 위쪽, 대각선왼쪽위 조사.
                // 가장 작은 것을 찾는다.
                dp[i][j] = min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1])) + 1;
                ans = max(ans, dp[i][j]);
            }
            
        }
    }

    cout<<ans*ans<<"\n";
    return 0;
}