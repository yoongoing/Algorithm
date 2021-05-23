#include <iostream>
#include <string>

using namespace std;

int check(int y, int x, int n){
    return y>=0 && x>=0 && y<n && x<n; 
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;

    char map[11][11] = {0,};
    int milestone[11][11] = {0,};

    int dy[8] = {-1,-1,-1,0,1,1,1,0};
    int dx[8] = {-1,0,1,1,1,0,-1,-1};
    
    for(int y=0; y<n; y++){
        string str;
        cin>>str;

        for(int x=0; x<str.size(); x++){
            map[y][x] = str[x];
            if(str[x] == '*'){
                for(int k=0; k<8; k++){
                    int ny = y + dy[k];
                    int nx = x + dx[k];

                    if(check(ny, nx, n))
                        milestone[ny][nx]++;
                    
                }
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            // if(flag && map[i][j]=='*')
            //     cout<<map[i][j]<<" ";

            // else
                cout<<map[i][j]<<" ";
        }
        cout<<"\n";    
    }
    cout<<"\n";
    int flag = 0;
    for(int y=0; y<n; y++){
        string str;
        cin>>str;
        
        for(int x=0; x<str.size(); x++){
            if(str[x] == '.')
                map[y][x] = '.';
            
            else{
                if(map[y][x] == '*'){
                    flag = 1;
                    continue;
                }
                map[y][x] = milestone[y][x] + '0';
            }     
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            // if(flag && map[i][j]=='*')
            //     cout<<map[i][j]<<" ";

            // else
                cout<<map[i][j]<<" ";
        }
        cout<<"\n";    
    }
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++)
    //         cout<<map[i][j]<<" ";
    //     cout<<"\n";
    // }
    return 0;
}