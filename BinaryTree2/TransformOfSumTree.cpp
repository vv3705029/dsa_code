#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data=data;
        left=right=NULL;
    }
};

static int idx=-1;
//BUILD TREE FROM PREORDER
Node* buildtree(vector<int>nodes){//O(n)
    idx++;
    if(nodes[idx]==-1){
        return NULL;
    }
    Node* currnode=new Node(nodes[idx]);

    currnode->left=buildtree(nodes);//LEFT SUBTREE
    currnode->right=buildtree(nodes);//RIGHT SUBTREE

    return currnode;
}


//TRANSFORM OF SUM OF TREE
int transform(Node* root){
    int leftold=transform(root->left);
    int rightold=transform(root->right);

    int currold=root->data;
    
    root->data=leftold+rightold;

    if(root->left!=NULL){
        root->data+=root->left->data;
    }
    if(root->right!=NULL){
        root->data+=root->right->data;
    }

    return currold;

}


void inorder(Node* root){
    if(root==NULL){
        return;
    }
    //LEFT
    inorder(root->left);
    //ROOT
    cout<<root->data<<" ";
    //RIGHT
    inorder(root->right);

}

int main(){
    vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root=buildtree(nodes);//1
    // cout<<"root:"<<root->data;
    
    transform(root);
    inorder(root);
    return 0;
}