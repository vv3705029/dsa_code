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

bool rootnodepath(Node* root,int n,vector<int>&path){
    if(root==NULL){
        return false;
    }

    path.push_back(root->data);

    if(root->data==n){
        return true;
    }

    int isleft=rootnodepath(root->left,n,path);
    int isright=rootnodepath(root->right,n,path);

    if(isleft || isright){
        return true;
    }
    path.pop_back();
    return false;
}
//LOWEST COMMEN ANCESTER
int LCA(Node* root,int n1,int n2){
    vector<int>path1;
    vector<int>path2;


    rootnodepath(root,n1,path1);
    rootnodepath(root,n2,path2);
    
    int lca=-1;
    for(int i=0,j=0;i<path1.size() && j<path2.size();i++,j++){
        if(path1[i]!=path2[j]){
            return lca;
        }
        lca=path1[i];
    }
}


//Approach2
Node* LCA2(Node* root,int n1,int n2){
    if(root==NULL){
        return NULL;
    }
    if(root->data==n1 ||root->data==n2){
        return root;
    }

    Node* leftLCA=LCA2(root->left,n1,n2);
    Node* rightLCA=LCA2(root->right,n1,n2);

    if(leftLCA!=NULL && rightLCA!=NULL){
        return root;
    }

    return leftLCA==NULL?rightLCA:leftLCA;//if true return first else return second
}
int main(){
    vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root=buildtree(nodes);//1
    // cout<<"root:"<<root->data;
    int n1=4,n2=5;
    //Approach1
    // cout<<LCA(root,n1,n2);//lca=2

    //Approach2
    cout<<LCA2(root,n1,n2)->data;//lca=2
    return 0;
}