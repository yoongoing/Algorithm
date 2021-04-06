#include <iostream>
#include <vector>
#include <deque>
#include <queue>
using namespace std;

int K;
int magnet[4][8];
queue<pair<int, int> > rotation;
int mag_match[4][2] = {{-1,1},{0,2},{1,3},{2,-1}};


int multi(int n){
    int ans = 1;
    for(int i=1; i<=n; i++){
        ans *= 2;
    }
    return ans;
}

void rotate_magnet(int mag, int dir){
    if(dir == 1){
        int temp7 = magnet[mag][7];

        int temp = magnet[mag][0];
        int next;
        for(int i=1; i<8; i++){
            next = magnet[mag][i];
            magnet[mag][i] = temp;
            temp = next;

        }
        magnet[mag][0] = temp7;
    }
    
    else if(dir == -1){
        int temp0 = magnet[mag][0];

        int temp = magnet[mag][7];
        int next;
        for(int i=6; i>=0; i--){
            next = magnet[mag][i];
            magnet[mag][i] = temp;
            temp = next;
        }
        magnet[mag][7] = temp0;
    }
    return;
}
int conv_dir(int dir){
    if(dir == 1)
        return -1;
    return 1;
}
bool mag_check(int cur_mag, int mag){
    int result = false;
    if((cur_mag==0) && (mag==1)){
        if(magnet[cur_mag][2] != magnet[mag][6])
            result = true;
    }
    else if((cur_mag==1) && (mag==0)){
        if(magnet[cur_mag][6] != magnet[mag][2])
            result = true;
    }
    else if((cur_mag==1) && (mag==2)){
        if(magnet[cur_mag][2] != magnet[mag][6])
            result = true;
    }
    else if((cur_mag==2) && (mag==1)){
        if(magnet[cur_mag][6] != magnet[mag][2])
            result = true;
    }
    else if((cur_mag==2) && (mag==3)){
        if(magnet[cur_mag][2] != magnet[mag][6])
            result = true;
    }
    else if((cur_mag==3) && (mag==2)){
        if(magnet[cur_mag][6] != magnet[mag][2])
            result = true;
    }
    return result;
}

void sol(){
    int size = rotation.size();

    for(int i=0; i<size; i++){
        int cur_magnet = rotation.front().first;
        int cur_dir = rotation.front().second;
        rotation.pop();

        queue<pair<int, int> > q;
        queue<pair<int, int> > qq;
        int check[4] = {0,};
        
        check[cur_magnet] = 1;
        q.push(make_pair(cur_magnet, cur_dir));
        qq.push(make_pair(cur_magnet, cur_dir));

        while(!q.empty()){
            cur_magnet = q.front().first;
            cur_dir = q.front().second;
            for(int i=0; i<2; i++){
                int next = mag_match[q.front().first][i];
                    
                if(mag_match[q.front().first][i] == -1)
                    continue;
                
                if(mag_check(cur_magnet,next) && check[next]!=1){
                    check[cur_magnet] = 1;
                    q.push(make_pair(next,conv_dir(cur_dir)));
                    qq.push(make_pair(next,conv_dir(cur_dir)));
                }
            }
            q.pop();      
        }
        
        while(!qq.empty()){
            rotate_magnet(qq.front().first, qq.front().second);
            qq.pop();
        }
    }
}


int main(int argc, char** argv){
    int test_case;
    cin>>test_case;

    for(int T=1; T<=test_case; T++){
        cin>>K;
        for(int i=0; i<4; i++){
            for(int j=0; j<8; j++){
                cin>>magnet[i][j];
            }
        }
        for(int i=0; i<K; i++){
            int m,dir;
            cin>>m>>dir;
            rotation.push(make_pair(m-1,dir));
        }
        
        sol();
        
        int ans = 0;
        for(int i=0; i<4; i++){
            if(magnet[i][0] == 1){
                ans += multi(i);
            }
        }
        cout<<"#"<<T<<" "<<ans<<endl;
    }

    return 0;
}