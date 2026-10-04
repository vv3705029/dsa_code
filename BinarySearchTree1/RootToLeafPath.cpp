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
//PRINT THR PATH
void printpath(vector<int>&path){
    for(int i=0;i<path.size();i++){
        cout<<path[i]<<" ";
    }
    cout<<endl;
}
//HELPER FUNCTION
void pathhelper(Node* root,vector<int>&path){
    if(root==NULL){
        return;
    }
    path.push_back(root->data);
    
    if(root->left==NULL && root->right==NULL){
        printpath(path);
        path.pop_back();
        return;
    }
    pathhelper(root->left,path);
    pathhelper(root->right,path);

    path.pop_back();
}
//PRINT ROOT TO LEAF PATH
void roottoleafpath(Node* root){
    vector<int>path;
    pathhelper(root,path);
}
int main(){
    // int arr[6]={5,1,3,4,2,7};
    int arr[9]={8,5,3,1,4,6,10,11,14};
    Node* root=buildBST(arr,9);
    roottoleafpath(root);
    return 0;
}