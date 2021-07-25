#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> V;

void DtoB(int num){
    while(num != 0){
        V.push_back(num%2);
        num /= 2;
    }
}

int main(void){
    int num;
    cin>>num;
    DtoB(num+1);
    
    reverse(V.begin(), V.end());
    
    for(int i=1; i<V.size(); i++){
        if(V[i] == 0)
            cout<<"4";
        else
            cout<<"7";
    }
    cout<<"\n";

    return 0;
}