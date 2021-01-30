// 이분탐색 => 탐색하려는 배열은 정렬되어있어야함

#include <iostream>
#include <algorithm>
#include <vector>

#define endl '\n'

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin>>T;

    int N,M;
    int n[1001];
    int m[1001];
    cin>>N;
    for(int i=0; i<N; i++)
        cin>>n[i];
    cin>>M;
    for(int i=0; i<M; i++)
        cin>>m[i];

    vector <int> nv;
    vector <int> mv;

    // A의 모든 경우의 수
    for(int i=0; i<N; i++){
        int sum = n[i];
        nv.push_back(sum);
        for(int j=i+1; j<N; j++){
            sum += n[j];
            nv.push_back(sum);
        }
    }

    // B의 모든 경우의 수
    for(int i=0; i<M; i++){
        int sum = m[i];
        mv.push_back(sum);
        for(int j=i+1; j<M; j++){
            sum += m[j];
            mv.push_back(sum);
        }
    }
    // sort(nv.begin(), nv.end());
    sort(mv.begin(), mv.end());

    long long int ans = 0;
    for(int i=0; i<nv.size(); i++){
        int diff = T - nv[i];
        
        auto ub = upper_bound(mv.begin(), mv.end(), diff);
        auto lb = lower_bound(mv.begin(), mv.end(), diff);

        ans += ub - lb;
    }
    cout<<ans<<endl;

    return 0;
}