#include <iostream>
#include <string>

using namespace std;

void print_this(string &s){
    string *cur = this;
    cout<<cur<<"\n";
}

int main(){
    // int a = 1;
    // int* b = &a;

    // char str[3] = {'A', 'B', 'C'};
    string s = "abd"; 
    
    cout<<&s<<"\n";
    print_this(s);
    // cout<<a<<" "<<*b<<"\n";

    return 0;
}