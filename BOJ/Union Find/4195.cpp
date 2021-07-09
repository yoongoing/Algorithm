#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstring>

using namespace std;

int root[200002];
int cnt[200002];

int find(int a){
    if(a == root[a])
        return a;
    return root[a] = find(root[a]);
}

int Union(int a, int b){
    a = find(a);
    b = find(b);
    
    if(a < b){
        root[b] = a;
        cnt[a] += cnt[b];
        return cnt[a];
    }
    else if(a > b){
        root[a] = b;
        cnt[b] += cnt[a];
        return cnt[b];
    }
    return cnt[a];
    
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int test;
    cin>>test;
    for(int T=0; T<test; T++){
        map <string, int> M;
        int F;
        cin>>F;

        // 초기화
        for(int i=0; i<F*2; i++)
            cnt[i] = 1;
        for(int i=0; i<F*2; i++)
            root[i] = i;

        int idx = 0;
        for(int i=0; i<F; i++){
            string str1, str2;
            cin>>str1>>str2;
            
            if(M.find(str1) == M.end())
                M[str1] = idx++;
            
            if(M.find(str2) == M.end())
                M[str2] = idx++;
            
            cout<<Union(M[str1], M[str2])<<"\n";
        }
    }
    return 0;
}