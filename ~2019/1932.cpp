#include <iostream>
#include <algorithm>

using namespace std;

#define MIN -1

int n;
int tri[510][510] = {0,};
int dp[510][510];
int dy[2] = {-1, -1};
int dx[2] = {-1, 0};

void init(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++)
            dp[i][j] = MIN;
    }
    dp[1][1] = tri[1][1];
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    
    cin>>n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++)
            cin>>tri[i][j];
    }

    init();

    for(int i=2; i<=n; i++){
        for(int j=1; j<=i; j++){
            dp[i][j] = max(max(dp[i][j], dp[i-1][j-1] + tri[i][j]), dp[i-1][j] + tri[i][j]);
        }
    }

    int ans = -1;
    for(int i=1; i<=n; i++)
        if(dp[n][i] > ans)
            ans = dp[n][i];
    
    cout<<ans<<"\n";

    
    return 0;
}