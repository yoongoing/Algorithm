#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Jewel
{
    int weight;
    int value;
};

bool cmp(Jewel s1, Jewel s2){
    if(s1.weight < s2.weight)  
        return true;
    return false;
}



int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N,K;
    cin>>N>>K;

    Jewel jewels[N];
    int bags[K];

    for(int i=0; i<N; i++){
        cin>>jewels[i].weight>>jewels[i].value;
    }

    for(int i=0; i<K; i++){
        cin>>bags[i];
    }

    sort(jewels, jewels+N, cmp);
    sort(bags, bags+K);

    priority_queue<int> pq;
    long long sum = 0;
    int j = 0;
    for(int i=0; i<K; i++){
        while(j<N && jewels[j].weight <= bags[i])
            pq.push(jewels[j++].value);
       
        if(!pq.empty()){
            sum += pq.top();
            pq.pop();
        }
    }
    cout<<sum<<"\n";
    return 0;
}