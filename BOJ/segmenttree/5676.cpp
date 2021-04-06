#include <iostream>
#include <cmath>
#include <stdio.h>

using namespace std;

#define MAX 100000

struct SegmentTree{
    long *tree;
    long tree_size;

    // 트리의 노드갯수 설정
    SegmentTree(int N){
        int height = (int)ceil(log2(N));
        tree_size = 1 << (height + 1);
        tree = new long[tree_size];
    }

    int update(int node, int left, int right, int index, int value){
        if(left<=index && index<=right){
            if(left == right){
                tree[node] = value;
                return tree[node];
            }
            else{
                int mid = (left + right) / 2;

                int left_value = update(node*2, left, mid, index, value);
                int right_value = update(node*2+1, mid+1, right, index, value); 
                tree[node] = left_value * right_value;  

                return tree[node];
                
            }
        }
        return tree[node];
    }

    int query(int node, int left, int right, int qLeft, int qRight){
        // 벗어난 범위라면
        if((right<qLeft) || (qRight<left))
            return 1;
        
        // 범위 안이라면
        else if(qLeft<=left && right<=qRight){
            return tree[node];
        }
        // 걸쳤다면
        else{
            int mid = (left + right) / 2;
            return query(node*2, left, mid, qLeft, qRight) * query(node*2+1, mid+1, right, qLeft, qRight);
        }
    }
};

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // 수열의 크기 N, 게임의 라운드수 K
    int N, K;
    
    SegmentTree *Node = new SegmentTree(MAX);
    while(cin>>N>>K){    
        // N개의 숫자 Xi
        for(int i=1; i<=N; i++){
            int x;
            cin>>x;
            if(x > 0)
                Node->update(1, 1, N, i, 1);
            else if(x == 0)
                Node->update(1, 1, N, i, 0);
            else if(x < 0)
                Node->update(1, 1, N, i, -1);
        }

        for(int i=0; i<K; i++){
            char command;
            cin>>command;

            // C index value
            if(command == 'C'){
                int index, value;
                cin>>index>>value;
                
                if(value > 0)
                    Node->update(1, 1, N, index, 1);
                else if(value == 0)
                    Node->update(1, 1, N, index, 0);
                else if(value < 0)
                    Node->update(1, 1, N, index, -1);
            }
            // P multiply
            else{
                int qLeft, qRight;
                cin>>qLeft>>qRight;

                int ans = Node->query(1, 1, N, qLeft, qRight);

                if(ans > 0)
                    cout<<"+";
                else if(ans == 0)
                    cout<<"0";
                else if(ans < 0)
                    cout<<"-";

            }
        }
        cout<<"\n";        
    }
    return 0;
}