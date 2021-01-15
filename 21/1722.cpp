#include <iostream>

using namespace std;

int main(void){
    int fact[21];
    fact[0] = 1;
    for(int i=1; i<=20; i++)
        fact = fact[i-1] * i;
    return 0;
}