#include<iostream>
#include<vector>
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
//
Node* BSTfromSortedvector(vector<int>arr,int st,int end){
    
    if(st>end){
        return NULL;
    }

    int mid=st+(end-st)/2;
    Node* curr=new Node(arr[mid]);
    curr->left=BSTfromSortedvector(arr,st,mid-1);
    curr->right=BSTfromSortedvector(arr,mid+1,end);

    return curr;
}
//get inorder sequence
void getinorder(Node* root,vector<int>&nodes){
    if(root==NULL){
        return;
    }
    getinorder(root->left,nodes);
    nodes.push_back(root->data);
    getinorder(root->right,nodes);
}
//BALENCED BST
Node* BalancedBST(Node* root){
    //INORDER SEQUENCE
    vector<int>nodes;
    getinorder(root,nodes);

    return BSTfromSortedvector(nodes,0,nodes.size()-1);

}
int main(){
    Node* root=new Node(6);
    root->left=new Node(5);
    root->left->left=new Node(4);
    root->left->left->left=new Node(3);

    root->right=new Node(7);
    root->right->right=new Node(8);
    root->right->right->right=new Node(9);

    
    root=BalancedBST(root);
    preorder(root);
    return 0;
}