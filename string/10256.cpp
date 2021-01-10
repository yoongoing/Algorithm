#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

int ans = 0;

int num(char c){
    if(c == 'A')    return 0;
    if(c == 'G')    return 1;
    if(c == 'T')    return 2;
    return 3;
}

struct Trie
{
    Trie *node[4];
    Trie *fail;

    bool finish;

    Trie(){
        for(int i=0; i<4; i++)
            node[i] = NULL;
        finish = false;
        fail = NULL;
    }
    ~Trie(){
        for(int i=0; i<4; i++)
            if(node[i])
                delete node[i];
    }

    void insert(const char *str){
        if(!*str){
            finish = true;
            return;
        }

        int cur = num(*str);

        if(!node[cur])
            node[cur] = new Trie();

        node[cur]->insert(str + 1);
    }

    void init() { 
        queue<Trie*> q;
        q.push(this);
        while (!q.empty())
        { 
            Trie* now = q.front(); 
            q.pop(); 
            for (int i = 0; i < 4; i++) 
            { 
                Trie* next = now->node[i];
                if (!next) continue; 
                if (now == this) next->fail = this; 
                else { 
                    Trie* t = now->fail; 
                    while (t != this && !t->node[i]) 
                        t = t->fail; 
                    if (t->node[i]) 
                        t = t->node[i]; 
                    next->fail = t; 
                } 
                if (next->fail->finish) 
                    next->finish = true; 
                q.push(next); 
            } 
        } 
    }


    void query(string &str){
        Trie* now = this;
        
        for(int i=0; i<str.size(); i++){
            int cur = num(str[i]);

            while(now != this && !(now->node[cur]))
                now = now->fail;
            
            if(now->node[cur])
                now = now->node[cur];
            
            if(now->finish)
                ans++;
        }
    }
};






int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin>>T;
    
    for(int testcase=0; testcase<T; testcase++){
        int n,m;
        cin>>n>>m;

        string dna, marker;
        cin>>dna;
        cin>>marker;

        Trie *root = new Trie();
        ans = 0;

        root->insert(marker.c_str());

        for(int i=0; i<marker.size(); i++){
            for(int j=i+1; j<marker.size(); j++){
                string temp = marker;
                reverse(temp.begin()+i, temp.begin()+j+1);
                root->insert(temp.c_str());
            }
        }

        root->init();
        root->query(dna);

        cout<<ans<<'\n';
        delete root;
    }
    return 0;
}