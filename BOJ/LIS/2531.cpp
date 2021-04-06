#include <iostream>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N,d,k,c;
    cin>>N>>d>>k>>c;

    int arr[30001];
    int check[3001] = {0,};
    
    int total = 0;
    for(int i=0; i<N; i++){
        cin>>arr[i];
        if(i >= N-k){
            total += (check[arr[i]]++ == 0);
        }
    }

    int ans = 0;
    for(int i=0; i<N; i++){
        ans = max(ans, total + (check[c] == 0));
        total += (check[arr[i]]++ == 0);
        total -= (--check[arr[(i + N - k) % N]] == 0);
    }
    
    cout<<ans<<"\n";

    return 0;
}