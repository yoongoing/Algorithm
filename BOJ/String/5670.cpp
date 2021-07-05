#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;
bool inital;
char arr[100000][81];
int ans;

struct Trie{
    Trie* node[26];
    int cnt;
    bool finish;

    Trie(){
        for(int i=0; i<26; i++)
            node[i] = NULL;
        finish = false;
        cnt = 0;
    }

    ~Trie(){
        for(int i=0; i<26; i++)
            if(node[i] != NULL)
                delete node[i];
    }

    int to_num(char c){
        return tolower(c) - 'a';
    }

    void insert(char *words){
        if(*words == '\0'){
            finish = true;
            return;
        }
        
        int cur = to_num(*words);

        if(node[cur] == NULL){
            node[cur] = new Trie();
            cnt++;
        }
        
        // 주소값 1 증가 == 다음 단어 가리키기
        node[cur]->insert(words + 1); 
    }

    void find(char* words){
        

        if(*words == '\0')
            return;
        
        if(inital){
            inital = false;
            ans++;
        }
        else{
            if(finish)
                ans++;
            else if(cnt > 1)
                ans++;
        }
        
        int cur = to_num(*words);
        node[cur]->find(words + 1);
    }
};

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    while(cin>>N){
        Trie* root = new Trie();
        ans = 0;

        for(int i=0; i<N; i++){
            cin>>arr[i];
            root->insert(arr[i]);
        }
        for(int i=0; i<N; i++){
            inital = true;
            root->find(arr[i]);
        }
        cout<<fixed<<setprecision(2)<<(double)ans / (double)N<<"\n";
        delete root;
    }
}