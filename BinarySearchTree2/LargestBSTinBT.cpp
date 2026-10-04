#include<iostream>
#include <limits.h>
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

class Info{
public:
   bool isBST;
   int min;
   int max;
   int size;
   Info(bool inBST,int min,int max,int size){
       this->isBST=isBST;
       this->min=min;
       this->max=max;
       this->size=size;

   }

};

static int maxSize;

Info* largestBST(Node* root){
    // BOTH BASE CASES ARE VALID
    // if(root==NULL){
    //     return new Info(true,INT_MAX,INT_MIN,0);
    // }

    if(root==NULL){
        return NULL;
    }
    if(root->left==NULL && root->right==NULL){
        return new Info(true,root->data,root->data,1);
    }
   Info* leftInfo=largestBST(root->left);
   Info* rightInfo=largestBST(root->right);

   
   int currmin=min(root->data,min(leftInfo->min,rightInfo->min));
   int currmax=max(root->data,max(leftInfo->max,rightInfo->max));;
   int currsize=leftInfo->size+rightInfo->size+1;
   
   if(leftInfo->isBST && rightInfo->isBST && root->data>leftInfo->max && root->data<rightInfo->min){
       maxSize=max(maxSize,currsize);
       return new Info(true,currmin,currmax,currsize);
   } else{
       return new Info(false,currmin,currmax,currsize);
   }
}
int main(){
    Node* root=new Node(50);
    root->left=new Node(30);
    root->left->left=new Node(5);
    root->left->right=new Node(20);

    root->right=new Node(60);
    root->right->left=new Node(45);
    root->right->right=new Node(70);
    root->right->right->left=new Node(65);
    root->right->right->right=new Node(80);
    
    largestBST(root);
    cout<<"max size:"<<maxSize;

    return 0;

}