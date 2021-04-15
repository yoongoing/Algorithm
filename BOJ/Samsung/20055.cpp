#include <iostream>

using namespace std;

int N,K;
int A[210];
int robot[105];

int check(){
    int cnt = 0;
    for(int i=0; i<2*N; i++){
        if(A[i] == 0)
            cnt++;
    }        
    return cnt;
}

void move(int cnt){
    for(int i=N-1; i>=0; i--){
        if(i == N-1){
            robot[i] = 0;
            continue;
        }
        
        // 이동하려는 칸에 로봇이 없으며, 그 칸의 내구도가 1 이상 남아 있어야 한다.
        if(robot[i] && !robot[i+1] && A[i+1]>0){
            robot[i] = 0;
            robot[i+1] = 1;
            A[i+1]--;
        }
    }
}

void shift(){
    int temp = A[2*N-1];
    for(int i=2*N-1; i>0; i--){
        A[i] = A[i-1];
    }
    A[0] = temp;

    for(int i=N-1; i>0; i--)
        robot[i] = robot[i-1];
    robot[0] = 0; 
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>N>>K;
    for(int i=0; i<2*N; i++){
        cin>>A[i];
    }

    int ans = 1;
    // 내구도가 0인 칸의 개수가 K개 이상이라면 과정을 종료
    while(1){
        // 벨트가 한 칸 회전한다
        shift();

        // 가장 먼저 벨트에 올라간 로봇부터, 벨트가 회전하는 방향으로 한 칸 이동할 수 있다면 이동한다
        // 이동할 수 없다면 가만히 있는다.
        move(ans);
        
        // 올라가는 위치에 로봇이 없다면 로봇을 하나 올린다.
        if(robot[0] == 0 && A[0] != 0){
            robot[0] = 1;
            A[0]--;
        }
        // 내구도가 0인 칸의 개수가 K개 이상이라면 과정을 종료
        if(check() >= K){
            cout<<ans<<"\n";
            return 0;
        }
        ans++;
    }
    return 0;
}

/*
#include <iostream>

using namespace std;

int N,K;
int convey[202] = {0,};
int robot[101] = {0,};

int count(int cnt){
    for(int i=1; i<=2*N; i++)
        if(convey[i] == 0)
            cnt++;
    return cnt;
}

void rshift(){
    for(int i=N; i>=1; i--){
        // 내구도가 있고, 로봇이 없으면 움직일 수 있다.
        if(convey[i]>0 && robot[i]==0){
            // cout<<i<<" "<<i-1<<"\n";
            robot[i] = robot[i-1];
            robot[i-1] = 0;
            if(robot[i])
                convey[i]--;
            
        }

        if(i==N && robot[i])
            robot[i] = 0;
    }

}

void shift(){
    int ctemp = convey[2*N];

    for(int i=2*N; i>=1; i--){
        convey[i] = convey[i-1];
    }
    convey[1] = ctemp;

    for(int i=N; i>=1; i--){
        robot[i] = robot[i-1];
        
        if(i==N && robot[i])
            robot[i] = 0;
    }

}

int sol(){
    int step = 1;

    while(1){
        // 1
        shift();

        // 2
        rshift();

        // 3
        if(!robot[1] && convey[1]>0){
            robot[1] = 1;
            convey[1]--;
        }

        // 4
        if(count(0) >= K)
            break;
        
        step++;
    }

    return step;
}


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>N>>K;
    for(int i=1; i<=2*N; i++){
        cin>>convey[i];
    }
    cout<<sol()<<"\n";
}
*/