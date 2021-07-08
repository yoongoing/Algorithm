#include <iostream>
#include <string>

using namespace std;

string NtoB(int N, int B){
    string str = "";
    string alpha = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int d = N, r;
    while(N >= B){
        d = N / B;
        r = N % B;
        // cout<<d<<", "<<r<<"\n";
        str += alpha[r];
        N = d;
        // cout<<str<<"\n";
    }
    str += alpha[d];
    return str;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N,B;
    cin>>N>>B;

    string str = NtoB(N,B);
    for(int i=str.size()-1; i>=0; i--)
        cout<<str[i];
    return 0;
}