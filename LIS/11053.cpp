#include <iostream>

using namespace std;

#define MAX 1001

int s[MAX];
int l[MAX];
int N;

int my_lower_bound(int start, int end, int target){
    int ans;

    while(start <= end){
        int mid = (start + end) / 2;

        if(l[mid] >= target){
            ans = mid;
            end = mid - 1;
        }
            
        else
            start = mid + 1;
    }

    return ans;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>N;
    for(int i=0; i<N; i++){
        cin>>s[i];
    }

    l[0] = s[0];
    int end = 0;

    for(int i=1; i<N; i++){
        if(s[i] <= l[end]){
            int index = my_lower_bound(0, end, s[i]);
            l[index] = s[i];
        }
        else
            l[++end] = s[i];
        
    }

    cout<<end+1<<"\n";
    for(int i=0; i<end+1; i++)
        cout<<l[i]<<" ";
    cout<<"\n";

    return 0;
}