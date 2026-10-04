#include<iostream>
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
//INSERT
Node* insert(Node* root,int val){//O(log(n))
    if(root==NULL){
        root=new Node(val);
        return root;
    }

    if(val<root->data){
        root->left=insert(root->left,val);
    }else{
        root->right=insert(root->right,val);
    }

    return root;
}
//Build a binary search tree
Node* buildBST(int arr[],int n){
    Node* root=NULL;
    for(int i=0;i<n;i++){
        root=insert(root,arr[i]);
    }

    return root;
}

void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
//get Inorder Successor
Node* getInorderSuccessor(Node* root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}

//delete node(
Node* delnode(Node* root,int val){
    if(root==NULL){
        return NULL;
    }

    if(val<root->data){//left subtree
        root->left=delnode(root->left,val);
    }else if(val>root->data){
        root->right=delnode(root->right,val);
    }else{
        //root==val
        //case1;0  children

        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        //case2;1 children
        if(root->left==NULL || root->right==NULL){
            return root->left==NULL?root->right:root->left;
        }
        //case3;2 children
        Node* IS=getInorderSuccessor(root->right);
        root->data=IS->data;
        delnode(root->right,IS->data);//case1 case2
    }
    return root;
}
int main(){
    // int arr[6]={5,1,3,4,2,7};
    int arr[9]={8,5,3,1,4,6,10,11,14};
    Node* root=buildBST(arr,9);
    inorder(root);
    cout<<endl;
    delnode(root,5);

    cout<<endl;
    inorder(root);

    cout<<endl;
    delnode(root,10);

    cout<<endl;
    inorder(root);
    return 0;
}