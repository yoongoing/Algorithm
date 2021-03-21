#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N,M;
int str[10001] = {0,};
int alpha = 0;

void init(){
    for(int i=0; i<26; i++)
        alpha += (1<<i);
}


int sol(){
    int cnt = 0;

    for(int i=0; i<N; i++){
        if((str[i] & alpha) == str[i])
            cnt++;
        
    }
    return cnt;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>N>>M;
    for(int i=0; i<N; i++){
        string s;
        cin>>s;
        
        for(int j=0; j<s.size(); j++){
            int idx = s[j] - 'a';
            str[i] |= (1<<idx);
        }
    }

    init();

    for(int i=0; i<M; i++){
        int o;
        char x;
        cin>>o>>x;

        // 기억 조작
        alpha ^= (1 << (x - 'a'));

        cout<<sol()<<"\n";
    }
    return 0;
}