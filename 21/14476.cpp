// 유클리드 호제법, 정수론, 누적론
#include <iostream>

using namespace std;


int gcd(int a, int b){
    if(b == 0)
        return a;
    return gcd(b, a%b);
}

int main(void){
    int N;
    cin>>N;

    
    int num[N];
    int left_to_right[N];
    int right_to_left[N];
    
    for(int i=0; i<N; i++){
        cin>>num[i];
    }

    int G = num[0];
    left_to_right[0] = G;
    for(int i=1; i<N; i++){
        G = gcd(G, num[i]);
        left_to_right[i] = G;
    }    

    G = num[N-1];
    right_to_left[N-1] = G;
    for(int i=N-2; i>=0; i--){
        G = gcd(G, num[i]);
        right_to_left[i] = G;
    }
    int ans = -1;
    int index;
    for(int idx=0; idx<N; idx++){
        if(idx == 0)
            G = right_to_left[1];
        else if(idx == N-1)
            G = left_to_right[N-2];
        else
            G = gcd(left_to_right[idx-1], right_to_left[idx+1]);
        
        if(num[idx]%G){
            ans = max(ans, G); 
            index = idx;
        }
    }
    
    if(ans == -1){
        cout<<ans<<"\n";
    }
    else
        cout<<ans<<" "<<num[index]<<"\n";
    
    return 0;
}