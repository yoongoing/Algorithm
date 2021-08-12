#include <iostream>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin>>N;

    int H = 2 * N - 1;
    for(int i=0; i<H; i++){
        if(i==0 || i==2*N-2){
            for(int j=0; j<N; j++)      cout<<"*";
            for(int j=0; j<2*N-3; j++)  cout<<" ";
            for(int j=0; j<N; j++)      cout<<"*";
        }
        else if(i == N-1){
            for(int j=0; j<N-1; j++)    cout<<" ";
            cout<<"*";
            for(int j=0; j<N-2; j++)    cout<<" ";
            cout<<"*";
            for(int j=0; j<N-2; j++)    cout<<" ";
            cout<<"*";
        }
        else{
            for(int j=0; j<(N-1)-abs(N-1-i); j++)   cout<<" ";
            cout<<"*";
            for(int j=0; j<N-2; j++)                cout<<" ";
            cout<<"*";
            for(int j=0; j<2 * abs(N-i-1) -1; j++)  cout<<" ";
            cout<<"*";
            for(int j=0; j<N-2; j++)                cout<<" ";
            cout<<"*";
        }
        cout<<"\n";
    }
    return 0;
}