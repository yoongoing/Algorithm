#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int MAX = 1000000;

struct Tree{
    long *tree;
    long tree_size;

    Tree(int N){
        int height = (int)ceil(log2(N));
        tree_size = 1 << (height + 1);
        tree = new long[tree_size];
    }

    void update(int node, int left, int right, int index, int diff){
        //index가 범위안에 있을때만
        if(left<=index && index<=right){

            //현재 노드에 diff추가
            tree[node] += diff;

            // leaf노드가 아닐때만
            if(left != right){
                int mid = (left + right) / 2;
                update(node*2, left, mid, index, diff);
                update(node*2+1, mid+1, right, index, diff);
            }
        }
    }

    long query(int node, int left, int right, int target){
        if(left==right){ // 리프에 도달
            return left;
        }
        else{
            int mid = (left + right) / 2;
            if(tree[node * 2] >= target){ // 왼쪽 값이 쿼리를 포함하는 경우
                return query(node*2, left, mid, target);
            }
            else{// 오른쪽으로 가야하는 경우
                return query(node*2+1, mid+1, right, target-tree[node*2]);
            }
        }
    }
};


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    Tree *root = new Tree(MAX);

    int N;
    cin>>N;
    for(int i=0; i<N; i++){
        int num;
        cin>>num;

        if(num == 1){
            int rank;
            cin>>rank;

            int idx = root->query(1, 1, MAX, rank);
            root->update(1, 1, MAX, idx, -1);

            cout<<idx<<"\n";
        }
        else if(num == 2){
            int rank;
            long long value;
            cin>>rank>>value;

            root->update(1, 1, MAX, rank, value);

        }
    }
    

    return 0;
}