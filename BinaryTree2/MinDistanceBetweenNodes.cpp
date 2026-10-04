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
//DISTANCE
int distance(Node* root,int n){
    if(root==NULL){
        return -1;
    }

    if(root->data==n){
        return 0;
    }

    int leftdis=distance(root->left,n);
    if(leftdis!= -1){
        return leftdis+1;
    }

     int rightdis=distance(root->right,n);
    if(rightdis!= -1){
        return rightdis+1;
    }
}
//MINDISTANCE
int mindistance(Node* root,int n1,int n2){
    Node* lca=LCA2(root,n1,n2);

    int dis1=distance(lca,n1);
    int dis2=distance(lca,n2);

    return dis1+dis2;

}
int main(){
    vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root=buildtree(nodes);//1
    // cout<<"root:"<<root->data;
    int n1=4,n2=6;
    //Approach2
    cout<<"Min Distance:"<<mindistance(root,n1,n2);//lca=2
    return 0;
}