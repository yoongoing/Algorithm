#include <iostream>

using namespace std;

int N;
char map[501][501];

void draw(int y, int x, int cnt){
    if(cnt == 1){
        // cout<<"1\n";
        for(int i=0; i<5; i++){
            map[y][x+i] = '*';
            map[y+6][x+i] = '*';
        }
        // cout<<"2\n";
        for(int i=1; i<6; i++)
            map[y+i][x] = '*';
        // cout<<"3\n";
        for(int i=2; i<6; i++){
            map[y+i][x+4] = '*';
            if(i > 4)
                continue;
            map[y+i][x+2] = '*';
        }
        // cout<<"4\n";
        map[y+2][x+3] = '*';
        return;
    }
    
    for(int i=0; i<4*cnt+1; i++){
        map[y][x+i] = '*';
        map[y+ 7+4*(cnt-1)-1][x+i] = '*';
    }
    for(int i=1; i<7+4*(cnt-1); i++){
        map[y+i][x] = '*';
        if(i == 1)
            continue;
        map[y+i][x+(4*cnt)] = '*';
    }
    map[y+2][x+(4*cnt-1)] = '*';
    draw(y+2, x+2, cnt-1);

}

void print(){
    for(int i=0; i<7+4*(N-2); i++){
        if(i == 1){ // 두번째줄 옆에 공백 출력하면 틀림. 
            cout<<"*\n";
            continue;
        }
        for(int j=0; j<5+4*(N-2); j++)
            cout<<(map[i][j]=='*'?'*':' ');
        cout<<"\n";
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>N;
    if(N == 1){
        cout<<"*\n";
        return 0;
    }
    // cout<<"start!\n";
    draw(0, 0, N-1);
    print();
    return 0;
}
