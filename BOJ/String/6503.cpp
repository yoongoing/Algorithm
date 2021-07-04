#include <iostream>
#include <string>
#include <cstring>

using namespace std;



void find(int M, string str){
    int key[128] = {0,};
    int right=-1, left=-1, cnt=0, res=0;
    int size = str.size();

    while(left <= right){
        if(cnt<M || (cnt==M && key[str[right+1]]>0)){
            right++;
            key[str[right]]++;
            if(key[str[right]] == 1)
                cnt++;
        }
        else{
            left++;
            key[str[left]]--;
            if(key[str[left]] == 0)
                cnt--;
        }
        res = max(right - left, res);
        if(right == size - 1)
            break;
    }
    cout<<res<<"\n";
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);


    while(1){
        int M;
        string str;
        cin>>M;
        
        if(M == 0)
            break;

        getline(cin, str);
        getline(cin, str);
        
        find(M, str);
    }

    return 0;
}