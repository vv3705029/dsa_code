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
//PRINTING A TREE
void    preorder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

//SORTED ARRAY TO BALNCED BST
Node* buildBSTfromSortedArray(int arr[],int st,int end){
    
    if(st>end){
        return NULL;
    }

    int mid=st+(end-st)/2;
    Node* curr=new Node(arr[mid]);
    curr->left=buildBSTfromSortedArray(arr,st,mid-1);
    curr->right=buildBSTfromSortedArray(arr,mid+1,end);

    return curr;
}

int main(){
    int arr[7]={3,4,5,6,7,8,9};
    // int arr[9]={8,5,3,1,4,6,10,11,14};
    Node* root=buildBSTfromSortedArray(arr,0,6);
    preorder(root);
    return 0;
}