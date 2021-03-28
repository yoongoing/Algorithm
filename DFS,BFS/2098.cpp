#include <iostream>
#include <algorithm>
#include <cstring> //memset

using namespace std;

const int MAX = 16;
const int INF = 987654321;

int N;
int W[MAX][MAX];
int cache[MAX][1 << MAX];


int TSP(int here, int visited){
    //기저 사례: 모든 도시를 다 방문했을 때는 0번 도시로 돌아가고 종료
    if (visited == (1 << N) - 1){
        if (W[here][0] != 0)
            return W[here][0];
        return INF;
    }

    //메모이제이션
    int &result = cache[here][visited];
    if (result != -1)
        return result;
    result = INF;

    //다음 방문할 도시를 전부 시도

    for (int next = 0; next < N; next++){

        //이미 방문한 도시
        if (visited & (1 << next) || W[here][next]==0)
            continue;

        int candidate = W[here][next] + TSP(next, visited + (1 << next));
        result = min(result, candidate);
    }

    return result;
}

 

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>N;
    if (N<2 || N>MAX)
        exit(-1);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> W[i][j];

    int result = INF;
    memset(cache, -1, sizeof(cache));

    cout << TSP(0, 1) << endl;
    return 0;
}

