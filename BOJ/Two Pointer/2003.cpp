#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    long M = 0;
    cin>>N>>M;
    
    int A[10001];
    for(int i=0; i<N; i++)
        cin>>A[i];
    
    int p1=0, p2=0;
    long sum = A[p1];
    int cnt = 0;
    while(p1<=p2 && p2<N){
        // cout<<p1<<" ~ "<<p2<<": "<<sum<<"\n";

        if(sum<M)
            sum += A[++p2];
        
        else if(sum == M){
            cnt++;
            sum += A[++p2];
        }
        else if(sum > M)
            sum -= A[p1++];

            if(p1>p2 && p1<N){
                p2 = p1;
                sum = A[p1];
            }
    }
    cout<<cnt<<"\n";
    return 0;
}