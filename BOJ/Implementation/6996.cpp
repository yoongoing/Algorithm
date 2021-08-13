#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin>>N;

    for(int i=0; i<N; i++){
        string str1, str2;
        cin>>str1>>str2;

        string s1=str1, s2=str2;
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());

        if(s1.compare(s2) == 0)
            cout<<str1<<" & "<<str2<<" are "<<"anagrams.\n";
        else
            cout<<str1<<" & "<<str2<<" are NOT "<<"anagrams.\n";
    }
    return 0;
}