#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

int result[3];

void eGcd(int a, int b){
    int s0=1, t0=0, r0=a;
    int s1=0, t1=1, r1=b;

    int temp;

    while(r1 > 0){
        int q = r0 / r1;
        temp = r0 - (q*r1); // 새로운 r1값
        r0 = r1;
        r1 = temp;

        temp = s0 - (q*s1); // 새로운 s1값
        s0 = s1;
        s1 = temp;

        temp = t0 - (q*t1); // 새로운 t1값
        t0 = t1;
        t1 = temp;
    }

    result[0] = s0;
    result[1] = t0;
    result[2] = r0;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin>>N;

    /*  X : 인당 나눠줄 사탕의 수
        Y : 사탕 봉지의 수

        A * x + 1 = B * y 를
        Ax + By = C 형태로 변환한다면
        -Ax + By = 1         */

    
    int A, B;
    for(int i=0; i<N; i++){
        // A, B 입력
        cin>>A>>B;

        // G = gcd(A,B) 구함
        // G * k = C ==> C % D == 0
        eGcd(A,B);
        if(result[2] != 1)
            cout<<"IMPOSSIBLE\n";
        else{
            // x0 = s * C/D
            // y0 = t * C/D
            int x0 = result[0]; // C = 1, D = 1
            int y0 = result[1];

            // 일반해 공식
            // x = x0 + B/D * k
            // y = y0 + A/D * k
            // x < 0
            // x0 + B/D*k < 0
            // k < -x0 / B * D

            // 0 < y <= 1e9
            // 0 < y0 - A/D * K <= 1e9
            // -y0 < -A/D * k <= 1e9 - y0
            // (y0 - 1e9) / A * D <= k < y0 / A * D


            // (y0 - 1e9) / A * D <= k <  y0 / A * D
            //                       k < -x0 / B * D
            long kFromX = (long)ceil((double) -x0 / (double) B) - 1;
            long kFromY = (long)ceil((double) y0 / (double) A) - 1;
            
            // k의 max를 구한 후 그 k를 이용해서 y값을 구해냅니다. -> k가 커지면 y는 작아짐.
            long k = min(kFromX, kFromY);
            long y = y0 - A * k;

            // 그렇게 구한 y눈 가장 작은 y값.
            // 그 구한 y값이 1e9 보다 작거나 같으면 가능한 답.
            // 아니면 불가능한 답.
            if(y <= 1e9){
                cout<<y<<"\n";
            }
            else
                cout<<"IMPOSSIBLE\n";
        }
        memset(result, 0, sizeof(result));
    }
    
    
    // 확장 유클리드 호제법을 이용하여 s, t, r을 찾아냄.
    return 0;
}