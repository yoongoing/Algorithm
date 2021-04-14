#include <iostream>

using namespace std;

int N, M, K;
int arr[202][202];

void print(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(arr[i][j] == 0)
                continue;
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
}


void shift(int cmd){
    int copy_arr[202][202];

    if(cmd == 1){
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                copy_arr[i][j] = arr[N-i-1][j];
            }
        }
    }
    else if(cmd == 2){
        for(int j=0; j<M; j++){
            for(int i=0; i<N; i++){
                copy_arr[i][j] = arr[i][M-j-1];
            }
        }
    }
    else if(cmd == 3){
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                copy_arr[j][N-i-1] = arr[i][j];
            }
        }
        int temp = N;
        N = M;
        M = temp; 
    }

    else if(cmd == 4){
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                copy_arr[M-j-1][i] = arr[i][j];
            }
        }
        int temp = N;
        N = M;
        M = temp;     
    }  
    else if(cmd == 5){
        int gi = N/2;
        int gj = M/2;
        int dir = 0;
        for(int i=0; i<N; i+=gi){
            for(int j=0; j<M; j+=gj){
                
                for(int ii=i; ii<i+gi; ii++){
                    for(int jj=j; jj<j+gj; jj++){
                        
                        if(dir%4 == 0)
                            copy_arr[ii][jj+gj] = arr[ii][jj];
                            
                        else if(dir%4 == 1)
                            copy_arr[ii+gi][jj] = arr[ii][jj];
                            
                        else if(dir%4 == 2)
                            copy_arr[ii-gi][jj] = arr[ii][jj];
                            
                        else if(dir%4 == 3)
                            copy_arr[ii][jj-gj] = arr[ii][jj];    
                    }
                }
                dir++;
            }
        }
    }
    else if(cmd == 6){
        int gi = N/2;
        int gj = M/2;
        int dir = 0;
        for(int i=0; i<N; i+=gi){
            for(int j=0; j<M; j+=gj){
                
                for(int ii=i; ii<i+gi; ii++){
                    for(int jj=j; jj<j+gj; jj++){
                        
                        if(dir%4 == 0)
                            copy_arr[ii+gi][jj] = arr[ii][jj];
                            
                        else if(dir%4 == 1)
                            copy_arr[ii][jj-gj] = arr[ii][jj];
                            
                        else if(dir%4 == 2)
                            copy_arr[ii][jj+gj] = arr[ii][jj];
                            
                        else if(dir%4 == 3)
                            copy_arr[ii-gi][jj] = arr[ii][jj];    
                    }
                }
                dir++;
            }
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            arr[i][j] = copy_arr[i][j];
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>N>>M>>K;
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            cin>>arr[i][j];

    for(int i=0; i<K; i++){
        int cmd;
        cin>>cmd;
        shift(cmd);
    }
    print();

    return 0;
}