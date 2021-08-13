#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int MAX=-1;
    int MAX_idx=-1;
    int arr[9];
    for(int i=0; i<9; i++){
        cin>>arr[i];
        if(arr[i] > MAX){
            MAX = arr[i];
            MAX_idx = i+1;
        }
    }

    cout<<MAX<<"\n"<<MAX_idx<<"\n";
    return 0;
}