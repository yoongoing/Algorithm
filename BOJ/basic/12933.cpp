#include <iostream>
#include <string>
#include <deque>

using namespace std;

string str;
int duck = 0;
int check[2501] = {0,};
char ans[5] = {'q', 'u', 'a', 'c', 'k'};
deque<int> dq;

void print(){
    for(int i=0; i<str.size(); i++)
        cout<<check[i]<<" ";
    cout<<"\n";
}

void find(int idx, int n){
    int flag;
    for(int i=idx; i<str.size(); i++){
        if(str[i] == ans[n] && !check[i]){
            dq.push_back(i);
            n += 1;
        }

        if(n == 5){
            flag = 1;
            n = 0;
            while(!dq.empty()){
                int k = dq.front();
                dq.pop_front();
                check[k] = 1;
            }
        }       
    }

    if(flag)
        duck += 1;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>str;
    if(str.size() % 5 != 0){
        cout<<"-1\n";
        return 0;
    }
        

    for(int i=0; i<str.size(); i++){
        if(str[i] == 'q' && !check[i]){
            find(i, 0);
        }       
    }

    for(int i=0; i<str.size(); i++){
        if(!check[i]){
            cout<<"-1\n";
            return 0 ;
        }
            
    }
    if(duck == 0)
        cout<<"-1\n";
    else
        cout<<duck<<"\n";
    
    return 0;
}