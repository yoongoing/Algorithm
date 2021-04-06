#include <iostream>
#include <string>
#include <cctype>
#include <math.h>
#include <vector>

using namespace std;

long long convertor(string str, int c){
    long long sum = 0; int k = 0;
    for(int i=str.size()-1; i>=0; i--){
        int d;
        if('0'<=str[i] && str[i]<='9')  d = str[i] - '0';
        else    d = str[i] - 'a' + 10;
        sum += d * pow(c, k++);
    }
    return sum;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string A,B;
    cin>>A>>B;
    
    int Ax = -1, Bx = -1;
    for(int i=0; i<A.size(); i++){
        int d;
        if('0'<=A[i] && A[i]<='9')  d = A[i] - '0';
        else d = A[i] - 'a' + 10;
        Ax = max(Ax, d);
    }
    for(int i=0; i<B.size(); i++){
        int d;
        if('0'<=B[i] && B[i]<='9')  d = B[i] - '0';
        else d = B[i] - 'a' + 10;
        Bx = max(Bx, d);
    }

    vector<unsigned long long> a;
    vector<unsigned long long> b;
    for(int i=Ax+1; i<37; i++){
        a.push_back(convertor(A,i));
    }
    for(int i=Bx+1; i<37; i++){
        b.push_back(convertor(B,i));
    }

    int cnt = 0;
    unsigned long long mx = ((long long)1<<63);
    unsigned long long x;
    int ans_a, ans_b;
    for(int i=0; i<a.size(); i++){
        for(int j=0; j<b.size(); j++){
            if(i+Ax == j+Bx)    continue;
            if(a[i] == b[j] && a[i]<mx){
                cnt++;
                x = a[i];
                ans_a = i + Ax + 1;
                ans_b = j + Bx + 1;
            }
            if(a[i]>mx || b[j]>mx) continue;
        }
    }

    if(cnt == 0)
        cout<<"Impossible\n";
    else if(cnt > 1)
        cout<<"Multiple\n";
    else
        cout<<x<<" "<<ans_a<<" "<<ans_b<<"\n";

    return 0;
}