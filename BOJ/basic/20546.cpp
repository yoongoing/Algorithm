#include <iostream>

using namespace std;

int main(void){
    
    int n;
    cin>>n;

    int cost[14];
    for(int i=0; i<14; i++)
        cin>>cost[i];

    int J = 0;
    int J_cash = n;
    for(int i=0; i<14; i++){
        if(cost[i] <= J_cash){
            J += J_cash / cost[i];
            J_cash %= cost[i];
        }
    }

    int S = 0;
    int S_cash = n;
    for(int i=0; i<11; i++){
        // 증가
        if(cost[i]<cost[i+1] && cost[i+1]<cost[i+2]){
            S_cash += S * cost[i+3];
            S = 0;
        }

        // 하락
        if(cost[i]>cost[i+1] && cost[i+1]>cost[i+2]){
            S += S_cash/cost[i+3];
            S_cash %= cost[i+3];
        }
    }

    if(J_cash+cost[13]*J < S_cash + cost[13] * S)
        cout<<"TIMING\n";
    else if(J_cash+cost[13]*J > S_cash + cost[13] * S)
        cout<<"BNP\n";
    else
        cout<<"SAMESAME\n";
    
    return 0;
}