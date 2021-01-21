#include <iostream>
#include <cstring>

using namespace std;

int T,N;
int card[1010];



int k_play(int s, int e){
    // play
}

int m_play(int s, int e){
    // play
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>T;
    for(int test_case=0; test_case<T; test_case++){
        
        cin>>N;
        for(int i=1; i<=N; i++)
            cin>>card[i];
        
        cout<<k_play(1, N);
        memset(card, 0, sizeof(card));
    }
    return 0;
}