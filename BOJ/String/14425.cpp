#include <iostream>
#include <set>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N,M;
    cin>>N>>M;

    set<string> s;

    for(int i=0; i<N; i++){
        string str;
        cin>>str;

        if(s.find(str) == s.end())
            s.insert(str);
        else
            continue;
    }

    int cnt = 0;
    for(int i=0; i<M; i++){
        string str;
        cin>>str;

        if(s.find(str) != s.end())
            cnt++;

    }
    cout<<cnt<<"\n";
    return 0;
}
