#include <iostream>

using namespace std;

int N,X;
int map[40][20];

// void print(){
//     for(int i=0; i<N*2; i++){
//         for(int j=0; j<N; j++)
//             cout<<map[i][j]<<" ";
//         cout<<endl;
//     }
// }
int solve(){
    int i, j;
    int ans = 0;
    for(i=0; i<N*2; i++){
        int cnt = 1;
        for(j=0; j<N-1; j++){
            //경사가 같을때
            if(map[i][j] == map[i][j+1])
                cnt++;

            //오르막길일때
            else if(map[i][j]+1 == map[i][j+1] && cnt>=X)
                cnt = 1;
             
            //내리막길일때
            else if(map[i][j]-1 == map[i][j+1] && cnt>=0)
                cnt = -X+1;
            
            //경사가 2개 이상일때
            else
                break;
        }
        if(j==N-1 && cnt>=0){
            ans++;
        } 
    }
    return ans;
}


int main(){
    int test_case;
    cin>>test_case;

    for(int T=1; T<=test_case; T++){
        cin>>N>>X;
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                cin>>map[i][j];

        for(int j=0; j<N; j++)
            for(int i=0; i<N; i++)
                map[N+j][i] = map[i][j];
        
        cout<<"#"<<T<<" "<<solve()<<endl;
    }
    return 0;
}