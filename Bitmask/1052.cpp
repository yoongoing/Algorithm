#include <iostream>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N,K;
    cin>>N>>K;
    if(N <= K){
        cout<<0<<"\n";
        return 0;
    }

    int ans = 0;
    while(1){

        int tmp = N;
        int cnt = 0;
        while(tmp){
            if(tmp % 2)
                cnt++;
            tmp /= 2;
        }

        if(cnt <= K)
            break;
        
        N++;
        ans++;
    }
    cout<<ans<<"\n";
    return 0;
}