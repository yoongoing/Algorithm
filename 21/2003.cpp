#include <iostream>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N,M;
    cin>>N>>M;

    int num[10001] = {0,};
    for(int i=0; i<N; i++)
        cin>>num[i];

    int pt1, pt2;
    pt1 = 0;
    pt2 = 0;
    int ans = 0;
    int sum = num[0];

    while(pt1<=pt2 && pt2<N){
        if(sum < M)
            sum += num[++pt2];  
        
        else if(sum == M){
            ans++;
            sum += num[++pt2];
        }
        else if(sum > M){
            sum -= num[pt1++];
            
            if(pt1>pt2 && pt1<N){
                pt2 = pt1;
                sum = num[pt1]; 
            }
        }
    }

    cout<<ans<<"\n";
    return 0;
}