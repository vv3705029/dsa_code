#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
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
//KTH ANSECTER
int kthansester(Node* root,int node,int k){
    if(root==NULL){
        return -1;
    }

    if(root->data==node){
        return 0;
    }

    int leftdist=kthansester(root->left,node,k);
    int rightdist=kthansester(root->right,node,k);

    if(leftdist==-1 && rightdist==-1){
        return -1;
    }
    int validval= leftdist==-1 ? rightdist:leftdist;

    if(validval+1==k){
        cout<<"Kth Ansester:"<<root->data;
    }

    return validval+1;
}
int main(){
    vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root=buildtree(nodes);//1
    // cout<<"root:"<<root->data;
    int node=6,k=1;
    kthansester(root,node,k);
    return 0;
}