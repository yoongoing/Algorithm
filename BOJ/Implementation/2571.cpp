#include <iostream>

using namespace std;

int map[101][101] = {0,};

int check(int y, int x){
    return y>0 && y<=100 && x>0 && x<=100;
}

void draw(int y, int x){
    for(int i=y; i<y+10; i++)
        for(int j=x; j<x+10; j++)
            if(check(i,j))
                map[i][j] = 1;
}

int check(int si, int sj, int ei, int ej){
    for(int i=si; i<=ei; i++)
        for(int j=sj; j<=ej; j++)
            if(!map[i][j])
                return 0;
    return 1;
}

int main(void){
    int K;
    cin>>K;

    for(int i=0; i<K; i++){
        int y,x;
        cin>>y>>x;
        draw(y,x);
    }

    int ans = 100;

    // 시작점 
    for(int si=1; si<100; si++){
        for(int sj=1; sj<100; sj++){
            if(!map[si][sj])
                continue;

            // 끝점
            for(int ei=si+1; ei<=100; ei++){
                for(int ej=sj+1; ej<=100; ej++){
                    if(!map[ei][ej])
                        continue;

                    int area = (ei-si+1) * (ej-sj+1);
                    
                    if(area > ans)
                        if(check(si, sj, ei, ej))
                            ans = area;
                }
            }
        }
    }

    cout<<ans<<"\n";
    return 0;
}