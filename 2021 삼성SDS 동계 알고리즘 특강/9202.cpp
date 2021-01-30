#include <iostream>
#include <string>

using namespace std;

int dy[8] = {-1,0,1,1,1,0,-1,-1};
int dx[8] = {-1,-1,-1,0,1,1,1,0};

struct Trie{
    Trie *trie[26];
    int finish;

    Trie(){
        finish = 0;
        for(int i=0; i<N; i++)
            trie[i] = nullptr;
    }

    void insert(char *str){
        if(!*str){
            finish = 1;
            return;
        }

        int cur = *str - 'A';

        if(!trie[cur])
            trie[cur] = new Trie();
        
        trie[cur]->insert(str + 1);
    }

    int find(char *str){
        if(!*str){
            if(finish)
                return 1;
            return 0;
        }
        
        int cur = *str - 'A';

        if(!trie[cur])
            return 0;
        
        cout<<trie[cur]<<" ";
        
        return trie[cur]->find(str + 1);
        
    }

    void search(int y, int x, int length, Trie *node){
        // 1. 체크인
        visited[y][x] = 1;
        // sb.append(length);

        // 2. 목적지에 도달하였는가?
        // if(node.isEnd && !node.isHit){
        //     node.isHit = 1;
        //     sum += score[length];
        //     cnt++;
        //     string foundword = sb.tostring();
        // }
        // 3. 연결된 곳을 순회
        for(int i=0; i<8; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            // 4. 가능한가?
            if(ny>=0 && nx>=0 && ny<4 && nx<4){
                // 5. 간다
                search(ny, nx, length+1, node->trie[ny][nx]);
            }
        }
        
        // 6. 체크아웃
        visited[y][x] = 0;
        // sb.delete(length-1);

    }

};




int main(void){
    int w;
    cin>>w;
    for(int i=0; i<w; i++){

    }
    int b;
    cin>>b;
    for(int i=0; i<b; i++){
        string string;
        for(int i=0; i<4; i++){
            cin>>string;
        }
    }
    return 0;
}