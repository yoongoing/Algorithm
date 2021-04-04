#include <iostream>
#include <string>

using namespace std;

int N,M;
vector<string> name;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>N;
    for(int i=0; i<N; i++){
        string str;
        cin>>str;
        name.push_back(str);
    }

    
    return 0;
}