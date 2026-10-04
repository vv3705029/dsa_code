#include<iostream>
#include<vector>
#include<queue>
using namespace std;
//PRINTING OF BT
//RECURSIVE 1.PREORER 2.INORDER 3.POSETORDER
//ITRATIVE 1.Level Order

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
//PREORDER
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
    inorder(root);
    return 0;
}