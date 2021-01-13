#include <iostream>
#include <algorithm>

#define endl '\n'

using namespace std;

long long N,M;
long long tree[1000001];

int check(int height){
    long long redun = 0;

    for(int i=0; i<N; i++)
        if(tree[i] - height > 0)
            redun += tree[i] - height;  
    
    if(redun >= M)
        return 1;

    return 0;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>N>>M;

    long long low = 0;
    long long high = -1;
    long long ans = 0;
    for(int i=0; i<N; i++){
        cin>>tree[i];
        high = max(high, tree[i]);
    }

    while(low <= high){
        long long mid = (low + high) / 2;
        if(check(mid)){
            ans = max(ans, mid);
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    
    
    cout<<ans<<endl;

    return 0;
}