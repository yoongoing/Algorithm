#include <iostream>

using namespace std;

#define endl '\n'

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long  X,Y;
    cin>>X>>Y;

    int Z = (Y * 100)/ X;
    
    if(Z >= 99){
        cout<<"-1"<<endl;
        return 0;
    }
    
    int low = 0;
    int high = 1000000000;
    int ans = -1;

    while(low <= high){      
        int mid = (low + high) / 2;
        int nextZ = ((Y + mid) * 100) / (X + mid);
        
        if(Z >= nextZ){
            ans = mid + 1;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    
    cout<<ans<<endl;

    return 0;
}
