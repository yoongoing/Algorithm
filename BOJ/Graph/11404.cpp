#include <iostream>

using namespace std;

#define MAX 100 + 1

int n,m;
int floyd[MAX][MAX];

void init(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i == j)
                floyd[i][j] = 0;
            else
                floyd[i][j] = 987654321;
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // 도시의 개수 n
    // 버스의 개수 m
    cin>>n>>m;
    
    init();

    for(int i=0; i<m; i++){
        int a,b,c;
        cin>>a>>b>>c;
        if(floyd[a][b] > c)
            floyd[a][b] = c;
    }

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(floyd[i][k]!=987654321 && floyd[k][j]!=987654321)
                    floyd[i][j] = min(floyd[i][j], floyd[i][k]+floyd[k][j]);
            }
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(floyd[i][j] == 987654321)
                cout<<"0 ";
            else
                cout<<floyd[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}