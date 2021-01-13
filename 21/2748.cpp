#include <iostream>

#define endl '\n'

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin>>N;

    long long int fibo[91] = {0,};
    fibo[0] = 0;
    fibo[1] = 1;

    for(int i=2; i<=N; i++){
        fibo[i] = fibo[i-1] + fibo[i-2];
    }
    cout<<fibo[N]<<endl;
    return 0;
}