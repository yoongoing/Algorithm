#include <iostream>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    int stair[303] = {0,};
    int dp[303] = {0,};
    // 계단의 개수
    cin>>N;

    // 제일 아래에 놓인 계단부터 순서대로 각 계단에 쓰여 있는 점수
    for(int i=1; i<=N; i++){
        cin>>stair[i];
    }

    int cnt = 0;

    dp[1] = stair[1];
    dp[2] = stair[1] + stair[2];
    dp[3] = max(dp[1]+stair[3], stair[2]+stair[3]);

    for(int i=4; i<=N; i++){
        dp[i] = max(dp[i-2]+stair[i], dp[i-3]+stair[i-1]+stair[i]);
    }
    
    cout<<dp[N]<<"\n";
    return 0;
}