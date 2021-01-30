#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int dp[201][201];

int combination(int n, int r){
    if(n==r || r==0)
        return 1;
    else if(dp[n][r] != 0)
        return dp[n][r];

    return dp[n][r] = min((int)1e9, combination(n-1,r-1) + combination(n-1, r)); 
}

void query(int n, int m, long long k, string s){
    // n == 0 && m == 0
    if(n + m == 0){
        cout<<s<<"\n";
        return;
    }
    
    // n == 0
    if(n == 0){
        s.append("z");
        query(n, m-1, k, s);
    }
    // m == 0
    else if(m == 0){
        s.append("a");
        query(n-1, m, k, s);
    }
    // n+m-1 C m
    else{
        int leftcount = combination(n+m-1, m);
        if(k <= leftcount){
            s.append("a");
            query(n-1, m, k, s);
        }
        else{
            s.append("z");
            query(n, m-1, k-leftcount, s);
        }
    }
}

int main(void){
    // N 개의 a 
    // M 개의 z 
    int N, M;
    long long K;
    cin>>N>>M>>K;

    if(combination(N+M, M) < K){
        cout<<"-1\n";
        return 0;
    }
    query(N,M,K, "");

    return 0;
}