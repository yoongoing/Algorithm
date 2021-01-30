#include <iostream>
#include <cstring>

using namespace std;



struct Tree{
    Tree *tree[2];
    char data;

    Tree(){
        for(int i=0; i<2; i++)
            tree[i] = nullptr;
        data = '\0';
    }

    void set_left(Tree *left){
        this->tree[0] = left;
    }
    
    void set_right(Tree *right){
        this->tree[1] = right;
    }

    

    void inorder(Tree *tree){
        if(tree){
            inorder(&tree[0]);
            cout<<tree->data;
            inorder(&tree[1]);
        }
    } 

    void postorder(Tree *tree){
        if(tree){
            postorder(&tree[0]);
            postorder(&tree[1]);
            cout<<tree->data;
        }
    }
};

void preorder(Tree *tree){
    if(tree->data != '\0'){
        cout<<tree->data;
        preorder(&tree[0]);
        preorder(&tree[1]);
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin>>N;

    Tree *tree = new Tree[N];
    for(int i=0; i<N; i++){
        char cur, left, right;
        cin>>cur>>left>>right;

        if(cur != '.')
            tree[(int)(cur-'A')].data = cur;
        
        if(left != '.'){
            tree[(int)(cur-'A')].set_left(&tree[(int)(left-'A')]);
        }
        else
            tree[(int)(cur-'A')].set_left(NULL);
     
        if(right != '.')
            tree[(int)(cur-'A')].set_right(&tree[(int)(right-'A')]);
        else
            tree[(int)(cur-'A')].set_right(NULL);
    }
    Tree *root = &tree[0];
    cout<<root->tree[0]<<"\n";
    preorder(root);
    cout<<"\n";
    // root->inorder(root);
    // cout<<"\n";
    // root->postorder(root);
    // cout<<"\n";

    return 0;
}