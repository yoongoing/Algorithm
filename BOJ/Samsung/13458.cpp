#include <iostream>
#include <vector>

using namespace std;

int N,B,C;
vector<int> A;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>N;
    for(int i=0; i<N; i++){
        int n;
        cin>>n;
        A.push_back(n);
    }
    cin>>B>>C;

    long long sum = 0;
    for(int i=0; i<A.size(); i++){
        sum++;
        A[i] -= B;
        if(A[i] > 0){
            if(A[i]%C != 0){
                sum += A[i] / C + 1;
            }
            else 
                sum += A[i] / C;
        }
    }

    cout<<sum<<"\n";
    return 0;
}