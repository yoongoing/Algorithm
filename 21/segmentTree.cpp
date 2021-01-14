#include <iostream>

using namespace std;

int Tsize;
int N;

long make_tree(int node, int left, int right){
    if(left == right){
        if(left <= N)
            return tree[node] = nums[left];
        else
            return tree[node] = 0;
    }
    int mid = (left + right) / 2;
    tree[node] = make_tree(node*2, left, mid);
    tree[node] = make_tree(node*2+1, mid+1, right);

    return tree[node];
}

void update(int node, int left, int right, int index, long diff){//diff : 
    if(left<=index && index<=right){
        tree[node] += diff;

        if(left != right){
            int mid = (left + right) / 2;
            update(node*2, left, mid, index, diff);
            update(node*2+1, mid, right, index, diff);
        }
    }

}

long query(int node, int left, int right, int qLeft, int qRight){
    if(qRight < left || right < qLeft)
        return 0;
    else if(qLeft <= left && right <= qRight)
        return tree[node];
    else{
        int mid = (left + right) / 2;
        return query(node*2, left, mid, qLeft, qRight)\
                + query(node*2+1, mid+1, right, qLeft, qRight);
    }
}


int main(void){
    cin>>N;

    long nums[N+1];
    for(int i=1; i<=N; i++){
        cin>>nums[i];
    }

    int S = 1; //리프노드의수 : 2^D
    while(S < N){
        S *= 2;
    }
    long tree[2 * S];


    return 0;
}