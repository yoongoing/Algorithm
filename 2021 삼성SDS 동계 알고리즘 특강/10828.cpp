#include <iostream>
#include <string>

using namespace std;

int main(void){
    int N;
    string str;

    int stack[10001];
    int size = 0;

    cin>>N;
    for(int i=0; i<N; i++){
        cin>>str;

        if(str == "push"){
            int num;
            cin>>num;
            stack[size++] = num;
        }
        else if(str == "pop"){
            if(size == 0){
                cout<<"-1\n";
                continue;
            }
            cout<<stack[size-1]<<"\n";
            stack[size--] = 0;
        }
        else if(str == "size"){
            cout<<size<<"\n";
        }
        else if(str == "empty"){
            if(size == 0)
                cout<<"1\n";
            else 
                cout<<"0\n";
        }
        else if(str == "top"){
            if(size == 0){
                cout<<"-1\n";
                continue;
            }
            cout<<stack[size-1]<<"\n";
        }
    }

    return 0;
}