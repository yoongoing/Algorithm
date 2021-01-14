#include <iostream>
#include <string>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int front = 0;
    int back = 0;
    
    int N;
    cin>>N;
    string str;

    int queue[100001];
    for(int i=0; i<N; i++){
        cin>>str;

        if(str == "push"){
            int num;
            cin>>num;
            queue[back++] = num;
        }
        else if(str == "pop"){
            if(front == back){
                cout<<"-1\n";
                continue;
            }
            cout<<queue[front++]<<"\n";
        }
        else if(str == "size"){
            cout<<back-front<<"\n";
        }
        else if(str == "empty"){
            if(front == back)
                cout<<"1\n";
            else 
                cout<<"0\n";
        }
        else if(str == "front"){
            if(front == back){
                cout<<"-1\n";
                continue;
            }
            cout<<queue[front]<<"\n";
        }
        else if(str == "back"){
            if(front == back){
                cout<<"-1\n";
                continue;
            }
            cout<<queue[back-1]<<"\n";
        }
    }
    return 0;
}