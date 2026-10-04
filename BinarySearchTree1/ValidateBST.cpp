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
//PRINT BST USING INORDED
void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
//HELPER FUNCTION
bool validatehelper(Node* root,Node* min,Node* max){
    if(root==NULL){
        return true;
    }

    if(min!=NULL && root->data<min->data){
        return false;
    }

    if(max!=NULL && root->data>max->data){
        return false;
    }

    return validatehelper(root->left,min,root) && validatehelper(root->right,root,max);
    
}
//VALIDATE BST
bool validateBST(Node* root){
    return validatehelper(root,NULL,NULL);
}
int main(){
    // int arr[6]={5,1,3,4,2,7};
    int arr[9]={8,5,3,1,4,6,10,11,14};
    Node* root=buildBST(arr,9);
    cout<<validateBST(root);
    return 0;
}