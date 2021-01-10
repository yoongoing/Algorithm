#include <iostream>

using namespace std;

struct TRIE{
    bool finish;
    TRIE *Node[26];

    TRIE(){
        finish = false;
        for(int i=0; i<26; i++)
            Node[i] = NULL;
    }

    void insert(char *str){
        if(*str == NULL){
            finish = true;
            return;
        }

        int cur = *str - 'A';

        if(Node[cur] == NULL)
            Node[cur] = new TRIE();
        
        Node[cur]->insert(str + 1);
    }

    bool find(char *str){
        if(*str == NULL){
            if(finish)
                return true;
            return false;
        }

        int cur = *str - 'A';
        
        if(Node[cur] == NULL)
            return false;
        return Node[cur]->find(str + 1);
    }

    void sorted_print(TRIE *N, char str[], int idx){
        if(N->finish == true)
            cout<<str<<"\n";
        for(int i=0; i<26; i++){
            if(N->Node[i] != NULL){
                char c = i + 'A';
                str[idx] = c;
                N->sorted_print(N->Node[i], str, idx+1);
            }
        }
    }
};

int main(void){
    TRIE *Root = new TRIE();
    char *string[5];

    string[0] = "ZYX";
    string[1] = "BCG";
    string[2] = "ABC";
    string[3] = "BDE";
    string[4] = "ABCD";

    for(int i=0; i<5; i++)
        Root->insert(string[i]);
    
    for(int i=0; i<26; i++){
        if(Root->Node[i] != NULL){
            char str[5] = {0,};
            str[0] = i + 'A';
            Root->sorted_print(Root->Node[i], str, 1);
        }
    }
    return 0;
}