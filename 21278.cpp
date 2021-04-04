#include <iostream>
#include <cstring>

using namespace std;

int N,M;
int floyd[101][101] = {0,};

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>N>>M;
    memset(floyd, 10000, sizeof(floyd));
    for(int i=0; i<M; i++){
        int from, to;
        cin>>from>>to;
        floyd[from][to] = floyd[to][from] = 1;
    }

    for(int k=1; k<=N; k++){
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                if(i == j)  floyd[i][j] = 0;
                floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);
            }
        }
    }

    int temp = 0;
    int n1, n2;
    int mn = 10000;
    for(int i=1; i<N; i++){
        for(int j=i+1; j<=N; j++){
            temp = 0;
            for(int k=1; k<=N; k++){
                temp += min(floyd[k][i], floyd[k][j]) * 2;
            }

            if(temp <= mn){
                if((i<n1)&&(j<n2) || temp<mn){
                    mn = temp;
                    n1 = i;
                    n2 = j;
                }
            }
        }
    }
    cout<<n1<<" "<<n2<<" "<<mn<<"\n";
    return 0;
}