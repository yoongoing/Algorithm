// 아호-코라식

#include <iostream>
#include <string>
#include <queue>
#include <stdio.h>
using namespace std;

struct TRIE
{
    TRIE *node[26];
    TRIE *fail;
    bool finish;

    TRIE(){
        finish = false;
        for(int i=0; i<26; i++)
            node[i] = NULL;
    }

    void insert(const char *str){
        if(!*str){
            finish = true;
            return;
        }

        int cur = *str - 'a';
        if(!node[cur])
            node[cur] = new TRIE();

        node[cur]->insert(str + 1);
    }

    void init(){
        queue<TRIE*> q;
        q.push(this);

        while(!q.empty()){
            TRIE *now = q.front();
            q.pop();

            for(int i=0; i<26; i++){
                TRIE *next = now->node[i];

                if(!next)
                    continue;

                if(now == this)
                    next->fail = this;
                
                else{
                    TRIE *temp = now->fail;

                    while(temp!=this && temp->node[i]==NULL){
                        // cout<<this<<"\n";
                        temp = temp->fail;
                    }
                    
                    if(temp->node[i])
                        temp = temp->node[i];

                    next->fail = temp;
                }

                if(next->fail->finish)
                    next->finish = true;

                q.push(next);
            }
        }

    }

    bool query(string &str){
        TRIE *cur = this;

        for(int i=0; i<str.size(); i++){
            int now = str[i] - 'a';

            while(cur!=this && !(cur->node[now]))
                cur = cur->fail;

            if(cur->node[now]){
                cur = cur->node[now];
            }
            if(cur->finish)
                return true;
        }
        return false;
    }
};

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    TRIE *Root = new TRIE();

    int N;
    cin>>N;

    for(int i=0; i<N; i++){
        string s;
        cin>>s;
        Root->insert(s.c_str());
    }
    
    Root->init();

    int Q;
    cin>>Q;

    while(Q--){
        string s;
        cin>>s;

        if(Root->query(s))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }

    return 0;
}

