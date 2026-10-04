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


//get inorder sequence
void getinorder(Node* root,vector<int>&nodes){
    if(root==NULL){
        return;
    }
    getinorder(root->left,nodes);
    nodes.push_back(root->data);
    getinorder(root->right,nodes);
}

//FORM A BST FROM A SORTED VECTRO
Node* BSTfromSortedvector(vector<int>&arr,int st,int end){
    
    if(st>end){
        return NULL;
    }

    int mid=st+(end-st)/2;
    Node* curr=new Node(arr[mid]);
    curr->left=BSTfromSortedvector(arr,st,mid-1);
    curr->right=BSTfromSortedvector(arr,mid+1,end);

    return curr;
}

Node* merge(Node* root1,Node* root2){
    vector<int>nodes1;
    vector<int>nodes2;
    vector<int>merged;

    getinorder(root1,nodes1);
    getinorder(root2,nodes2);

    int i=0,j=0;
    while (i<nodes1.size() && j<nodes2.size()){
        if(nodes1[i]<nodes2[j]){
            merged.push_back(nodes1[i++]);
        }else{
            merged.push_back(nodes2[j++]);
        }
    }
    
    while(i<nodes1.size()){
        merged.push_back(nodes1[i++]);
    }

    while(j<nodes2.size()){
        merged.push_back(nodes2[j++]);
    }

    return BSTfromSortedvector(merged,0,merged.size()-1);


}

//PRINT A BST USING PREORDER
void preorder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";

    preorder(root->left);
    preorder(root->right);
}
int main(){
    Node* root1=new Node(2);
    root1->left=new Node(1);
    root1->right=new Node(4);

    Node* root2=new Node(9);
    root2->left=new Node(3);
    root2->right=new Node(12);
     

    Node* root= merge(root1,root2);

    preorder(root);
    cout<<endl;
    preorder(root2);
    return 0;
}