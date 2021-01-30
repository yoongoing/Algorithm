#include <iostream>
#include <stack>
#include <string>
#include <cstdlib>

using namespace std;

struct item
{
    char command;
    int num;

    item(){
        num = -1;
        command ='\n';
    }
    int isValue(){
        if(command == '\n')
            return 1;
        return 0;
    }
    int isCommand(){
        if(num == -1)
            return 1;
        return 0;
    }
};

stack<item> stk;

void print(void){
    stack<item> t = stk;
    while(!t.empty()){
        if(t.top().isValue())
            cout<<t.top().num<<" ";
        else{
            cout<<t.top().command<<" ";
        }
            
        t.pop();
    }
    cout<<"\n";
}

int main(void){
    string str;
    cin>>str;

    for(int i=0; i<str.size(); i++){
        char cmd = str[i];
        
        // command 입력
        if(cmd =='(' || cmd =='['){
            item next;
            next.command = cmd;
            stk.push(next);
        }
        else if(cmd == ')'){
            if(stk.empty()){
                cout<<"0\n";
                return 0;
            }

            int sum = 0;
            int flag = 1;

            while(!stk.empty()){
                item temp = stk.top(); 
                stk.pop();

                if(temp.isValue()){
                    sum += temp.num;
                }
                else if(temp.command == '('){
                    if(sum == 0){
                        item next;
                        next.num = 2;
                        stk.push(next);
                    }
                    else{
                        item next;
                        next.num = sum * 2;
                        stk.push(next);
                    }
                    flag = 0;
                    break;
                }
                else{
                    flag = 1;
                    break;
                }
            }
            if(flag){
                cout<<"0\n";
                return 0;
            }
        } 
        else if(cmd == ']'){
            if(stk.empty()){
                cout<<"0\n";
                return 0;
            }

            int sum = 0;
            int flag = 1;

            while(!stk.empty()){
                item temp = stk.top();
                stk.pop(); 

                if(temp.isValue()){
                    sum += temp.num;
                }
                else if(temp.command == '['){
                    if(sum == 0){
                        item next;
                        next.num = 3;
                        stk.push(next);
                    }
                    else{
                        item next;
                        next.num = sum * 3;
                        stk.push(next);
                    }
                    flag = 0;
                    break;
                }
                else{
                    flag = 1;
                    break;
                }
            }
            if(flag){
                cout<<"0\n";
                return 0;
            }
        }
        // print();
    }

    int sum = 0;
    while(!stk.empty()){
        item cur = stk.top();
        stk.pop();

        if(cur.isCommand()){
            cout<<"0\n";
            return 0;
        }
        sum += cur.num;
    }
    cout<<sum<<"\n";
    return 0;
}