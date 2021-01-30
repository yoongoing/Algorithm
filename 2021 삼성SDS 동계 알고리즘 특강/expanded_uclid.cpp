#include <iostream>

using namespace std;

// (ax + by = c) => (as + bt = r)을 만족하는 
//                    s,   t,  r(단, r=gcd(a,b)) 조합 찾기.
int* eGcd(int a, int b){
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
    int ans[] = {s0, t0, r0}; 
    return ans;
}

int main(void){
    
    
    return 0;
}