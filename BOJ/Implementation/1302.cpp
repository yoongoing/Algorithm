#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(void){
    int N;
    cin>>N;

    map<string, int> m;
    for(int i=0; i<N; i++){
        string str;
        cin>>str;
        
        if(m.find(str) == m.end())
            m[str] = 1;
        else
            m[str]++;
    }

    string KEY = "";
    int MAX = -1;
    for(auto &itr : m){
        if(MAX < itr.second){
            MAX = itr.second;
            KEY = itr.first;
        }
        if(MAX==itr.second && KEY > itr.first){
            KEY = itr.first;
        }
    }
    cout<<KEY<<"\n";
    return 0;
}