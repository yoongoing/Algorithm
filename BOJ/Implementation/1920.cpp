#include <iostream>
#include <map>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N,M;
    map<int, int> m;
    cin>>N;
    for(int i=0; i<N; i++){
        int A;
        cin>>A;
        m[A] = 1;
    }

    cin>>M;
    for(int i=0; i<M; i++){
        int B;
        cin>>B;
        if(m.find(B) != m.end())
            cout<<"1\n";
        else
            cout<<"0\n";
    }
    return 0;
}