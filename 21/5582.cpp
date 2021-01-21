#include <iostream>
#include <string>

using namespace std;

int dp[4002][4002];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    
    string str1;
    string str2;
    cin>>str1>>str2;

    int mx = 0;
    for(int i=0; i<str1.size(); i++){
        for(int j=0; j<str2.size(); j++){
            if(str1[i] == str2[j]){
                if(i == 0 || j == 0)
                    dp[i][j] = 1;
                else
                    dp[i][j] = dp[i-1][j-1] + 1;
                
                mx = max(mx, dp[i][j]);
            }
        }
    }

    cout<<mx<<"\n";
    return 0;
}