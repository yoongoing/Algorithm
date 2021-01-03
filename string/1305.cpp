#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, pi[1000001];
    char s[1000001];

    cin>>n>>s;

    int j = 0;
    for(int i=1; i<n; i++){
        
        while(s[i] != s[j] && j > 0)
            j = pi[j-1];
        
        if(s[i] == s[j]){
            pi[i] = ++j;
        } 
    }

    cout<<n-pi[n-1]<<"\n";
    return 0;
}