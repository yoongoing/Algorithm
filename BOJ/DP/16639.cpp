#include <iostream>
#include <string>
#include <climits>
#include <algorithm>

using namespace std;

int N;

int maxCache[10][10];
int minCache[10][10];

void init(void){
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            maxCache[i][j] = INT_MIN;
            minCache[i][j] = INT_MAX;
        }
    }
}

int cal(int a, int b, char cmd){
    if(cmd == '+')
        return a + b;
    else if(cmd == '-')
        return a - b;
    else if(cmd == '*')
        return a * b;
    
    return -1;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>N;
    
    string str;
    cin>>str;

    init();
    
    int n = (N + 1) / 2;
    for(int i=0; i<n; i++)
        maxCache[i][i] = minCache[i][i] = str[i * 2] - '0';

    for(int cnt=1; cnt<n; cnt++){
        for(int idx=0; idx<n-cnt; idx++){
            for(int i=1,j=cnt; i<=cnt; i++,j--){
                int cmdIdx = (idx + cnt - j) * 2 + 1;
                char cmd = str[cmdIdx];

                int candidates[4] = {\
                        cal(maxCache[idx][idx+cnt-j], maxCache[idx+i][idx+cnt], cmd),\
                        cal(maxCache[idx][idx+cnt-j], minCache[idx+i][idx+cnt], cmd),\
                        cal(minCache[idx][idx+cnt-j], maxCache[idx+i][idx+cnt], cmd),\
                        cal(minCache[idx][idx+cnt-j], minCache[idx+i][idx+cnt], cmd)};

                sort(candidates, candidates + 4);

                maxCache[idx][idx+cnt] = max(maxCache[idx][idx+cnt], candidates[3]);
                minCache[idx][idx+cnt] = min(minCache[idx][idx+cnt], candidates[0]);
            }
        }
    }

    int result = maxCache[0][n-1];
    cout<<result<<"\n";
    return 0;
}
