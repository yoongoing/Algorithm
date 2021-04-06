#include <iostream>

using namespace std;

typedef struct node *treenode;
typedef struct node{
    int value;
    treenode left;
    treenode right;
}node;


void preorder(treenode root){
    if(root){
        cout<<root->value<<"\n";
        preorder(root->left);
        preorder(root->right);
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int num = 15;

    node N[num+1];

    for(int i=1; i<=num; i++){
        N[i].value = i;
        N[i].left = nullptr;
        N[i].right = nullptr;
    }

    for(int i=1; i<=num; i++){
        if(i%2 == 0){
            N[i/2].left = &N[i];
        }
        else
            N[i/2].right = &N[i];
    }
    preorder(&N[1]);
    return 0;
}