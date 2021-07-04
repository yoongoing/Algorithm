#include <iostream>
#include <string>

using namespace std;

string str1;
string str2;
int dp[1010][1010] = {0,};

int mx = 0;
string ans;

void print(int i, int j){
    if(dp[i][j] == 0)
        return;
    if(str1[i-1] == str2[j-1]){
        print(i-1, j-1);
        cout<<str1[i-1];
    }
    else{
        if(dp[i-1][j] > dp[i][j-1])
            print(i-1, j);
        else
            print(i, j-1);
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>str1>>str2;
    int i, j;
    for(i=0; i<str1.size(); i++){
        for(j=0; j<str2.size(); j++){
            if(str1[i] == str2[j])
                dp[i+1][j+1] = dp[i][j] + 1;
            else
                dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
        }
    }
    cout<<dp[i][j]<<"\n";
    print(i,j);
    cout<<"\n";
    return 0;
}