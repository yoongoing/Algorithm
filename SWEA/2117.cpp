#include <iostream>
#include <math.h>

using namespace std;

int N,M;
int map[20][20];
int ans = 0;

bool check(int y, int x){
    if((y>=0) && (x>=0) && (x<N) && (y<N))
        return true;
    return false;
}

int cost(int k){
    int s = 0;
    s += (k*k) + ((k-1)*(k-1));
    return s;
}

void init_(){
    ans = 0;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            map[i][j] = 0;
}

void sol(){
    //마름모의 범위당
    for(int k=1; k<=N+1; k++){
        int total = 0;
        int max_manage = 0;
        //N*N범위를 체크하면서
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                int sum = 0;
                //해당좌표로부터 K범위확인
                for(int m=i-(k-1); m<=i+(k-1); m++){
                    for(int n=j-(k-1); n<=j+(k-1); n++){
                        //마름모 범위 안에 없다면
                        if((abs(i-m) + abs(j-n)) > (k-1))
                            continue;

                        //마름모 범위 안에 있으면서 집이 있다면
                        if(check(m,n) && map[m][n]!=0)
                            sum++;
                    }
                }
                //모든 범위 확인후 total에 저장
                if((M * sum - cost(k)) >= 0 && sum > ans) 
                    ans = sum;
            }
        }
    }
}

int main(int argc, char** argv){
    int test_case;
    cin>>test_case;
    for(int T=1; T<=test_case; T++){
        cin>>N>>M;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cin>>map[i][j];
            }
        }
        sol();
        cout<<"#"<<T<<" "<<ans<<endl;
        init_();
    }
    return 0;
}