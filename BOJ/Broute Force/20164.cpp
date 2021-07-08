#include <iostream>
#include <string>

using namespace std;

int Max= -1, Min = 987654321;

int cnt_odd(string str){
    int cnt = 0;
    for(int i=0; i<str.size(); i++){
        if((str[i]-'0')%2 != 0)
            cnt++;
    }
    return cnt;
}

void devide(string str, int cnt){

    if(str.size() == 1){
        cnt += cnt_odd(str);
        Max = max(Max, cnt);
        Min = min(Min, cnt);
        return;
    }

    else if(str.size() == 2){
        cnt += cnt_odd(str);
        int n = (str[0]-'0') + (str[1]-'0');
        devide(to_string(n), cnt);
    }

    else{
        cnt += cnt_odd(str);
        // 조합. nC2
        for(int i=1; i<str.size(); i++){
            for(int j=i+1; j<str.size(); j++){
                string part1 = str.substr(0, i-0);
                string part2 = str.substr(i, j-i);
                string part3 = str.substr(j, str.size()-j);

                int n = stoi(part1) + stoi(part2) + stoi(part3);
                devide(to_string(n), cnt);
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string str;
    cin>>str;

    devide(str, 0);
    cout<<Min<<" "<<Max<<"\n";
    return 0;
}