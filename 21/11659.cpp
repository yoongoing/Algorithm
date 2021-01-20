#include <iostream>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N,M;
    cin>>N>>M;

    int num[100002] = {0,};
    for(int i=1; i<=N; i++){
        int a;
        cin>>a;
        num[i] = num[i-1] + a;
    }

    for(int i=0; i<M; i++){
        int start, end;
        cin>>start>>end;

        cout<<num[end]-num[start-1]<<"\n";
    }
    return 0;
}