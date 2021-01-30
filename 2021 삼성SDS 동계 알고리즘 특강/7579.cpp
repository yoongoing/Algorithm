#include <iostream>
#include <cstring>

using namespace std;

int N,M;
int memory[110];
int cost[110];
int cache[110][10010];

int calc(int idx, int total_cost){
    if(idx >= 100) 
        return 0;
    
    int &result = cache[idx][total_cost];
    if(result != -1)
        return result;
    
    result = calc(idx+1, total_cost);

    if(cost[idx] <= total_cost){
        result = max(result, memory[idx] + calc(idx+1, total_cost-cost[idx]));
    }

    return result;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // 정수 N과 M
    cin>>N>>M;

    // N개의 정수만큼 메모리의 바이트 수 m
    for(int i=0; i<N; i++)
        cin>>memory[i];

    // 각 앱을 비활성화 했을 경우의 비용 c
    for(int i=0; i<N; i++)
        cin>>cost[i];

    memset(cache, -1, sizeof(cache));

    int total_cost = 0;
    while(1){
        int result = calc(0, total_cost);

        if(result >= M){
            cout<<total_cost<<"\n";
            break;
        }
        
        total_cost++;
    }
    
    return 0;
}