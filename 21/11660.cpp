#include <iostream>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    int map[1026][1026] = {0,};

    // 표의 크기 N
    cin>>N;
    // 합을 구해야 하는 횟수 M
    cin>>M;
    
    // 표에 채워져 있는 수
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            int a;
            cin>>a;
            map[i][j] = map[i][j-1] + map[i-1][j] - map[i-1][j-1] + a;

        }            
    }

    for(int i=0; i<M; i++){
        // 네 개의 정수 x1, y1, x2, y2
        int x1, y1, x2, y2;
        cin>>x1>>y1>>x2>>y2;

        // (x1, y1)부터 (x2, y2)의 합을 구해 출력
        cout<<map[x2][y2] - (map[x1-1][y2] + map[x2][y1-1]) + map[x1-1][y1-1]<<"\n";
    }

    
    return 0;
}
