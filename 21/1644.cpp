#include <iostream>
#include <string>

using namespace std;

#define MAX 1000001

int prime[MAX];


void make_prime(int k){
    for(int i=2; i<=k; i++){
        if(!prime[i]){
            for(int j=i+1; j<=k; j+=i)
                prime[i] = 1;
        }
    }
}

int main(void){
    string P;
    cin>>P;

    int K;
    cin>>K;

    make_prime(K);

    for(int i=2; i<K; i++){
        if(prime[i]){
            int n;
            int flag = 0;
            int next = 0;
            for(int j=0; j<P.size(); j++){
                n = (next*10) + (P[j] - '0');
                next = n % i;
            }
            if(!next){
                cout<<"BAD "<<i<<"\n";
                return 0;
            }          
        }
    }
    cout<<"GOOD\n";
    return 0;
}