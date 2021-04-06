#include <iostream>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m;
    int arr[100010];
    cin>>n>>m;

    int sum = 0;
    for(int i=1; i<=n; i++){
        cin>>arr[i];
        arr[i] += sum;
        sum = arr[i];
    }

    for(int i=0; i<m; i++){
        int start, end;
        cin>>start>>end;

        cout<<arr[end] - arr[start-1]<<"\n";
    }
        
    return 0;

}