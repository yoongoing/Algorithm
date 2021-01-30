#include <iostream>
#include <cstring>

using namespace std;

int T,N;
int card[1010];



int k_play(int s, int e){
    // play
    if(s == e)
        return card[s];

    // 가장 왼쪽을 가져가거나
    card[s], m_play(s+1,e);
    // 가장 오른쪽을 가져감
    card[e], m_play(s, e-1);
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