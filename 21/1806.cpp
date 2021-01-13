#include <iostream>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, S;
    cin>>N>>S;

    int num[100001] = {0,};
    for(int i=0; i<N; i++)
        cin>>num[i];

    int pt1, pt2;
    pt1 = 0;ㄴ
    pt2 = 0;
    int len = 987654321;
    int sum = num[0];

    while(pt1<=pt2 && pt2<N){
        if(sum < S)
            sum += num[++pt2];  
        else if(sum == S){
            len = min(len, pt2-pt1+1);
            sum += num[++pt2];
        }
        else if (sum > S){
            len = min(len, pt2-pt1+1);
            sum -= num[pt1++];
        }
    }
    if(len == 987654321)
        cout<<"0\n";
    else
        cout<<len<<"\n";
    return 0;
}