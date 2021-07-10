#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N,K;
int ans = 0;
int alpha[26] = {0,};
vector<string> V;

int check(int cnt){
    for(int i=0; i<V.size(); i++){
        string str = V[i];
        int flag = 1;
        for(int j=0; j<str.size(); j++){
            if(!alpha[str[j]-'a']){
                flag = 0;
                break;
            }
        }
        if(flag)
            cnt++;
    }
    return cnt;
}

void dfs(int idx, int cnt){
    if(cnt == K){
        ans = max(ans, check(0));
        return;
    }

    for(int i=idx+1; i<26; i++){
        if(!alpha[i]){
            alpha[i] = 1;
            dfs(i, cnt+1);
            alpha[i] = 0;
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>N>>K;
    
    for(int i=0; i<N; i++){
        string str;
        cin>>str;
        V.push_back(str);
    }
    // a n t i c 도 없다는 소리 = 남극의 언어가 없다는 소리 
    if(K < 5){
        cout<<"0\n";
        return 0;
    }
    alpha['a' - 'a'] = 1;
    alpha['n' - 'a'] = 1;
    alpha['t' - 'a'] = 1;
    alpha['i' - 'a'] = 1;
    alpha['c' - 'a'] = 1;
    K -= 5;

    dfs(-1, 0);
    cout<<ans<<"\n";
    return 0;
}