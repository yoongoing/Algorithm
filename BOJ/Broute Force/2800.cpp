#include <iostream>
#include <string>
#include <set>
#include <stack>

using namespace std;

set<string> s;
stack<char> stk;
int idx[201] = {0,};
string ret;
bool erase[201] = {0,};

void delet(int cur, int len, string str){
    if(cur == len){
        s.insert(ret);
        return;
    }

    if(str[cur] == '('){
        erase[idx[cur]] = 1;
        delet(cur+1, len, str);
        erase[idx[cur]] = 0;
    }

    if(str[cur] == ')' && erase[cur])
        delet(cur+1, len, str);
    else{
        ret += str[cur];
        delet(cur+1, len, str);
        ret.resize(ret.size()-1);
    }
}

int main(void){

    string str;
    cin>>str;

    for(int i=0; i<str.size(); i++){
        if(str[i] == '('){
            stk.push(i);
        }
        else if(str[i] == ')'){
            idx[i] = stk.top();
            idx[stk.top()] = i;
            stk.pop();
        }
    }

    delet(0, str.size(), str);
    s.erase(str);

    for(auto n : s)
        cout<<n<<"\n";
    return 0;
}