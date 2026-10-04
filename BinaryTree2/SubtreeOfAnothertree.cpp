#include<iostream>
#include<vector>
#include<queue>
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


//IDENTICAL FUNCTION
bool isidentical(Node* root1,Node* root2){
    //base case
    if(root1==NULL && root2==NULL){
        return true;
    }else if(root1==NULL || root2==NULL){
        return false;
    }


    if(root1->data!=root2->data){
        return false;
    }

    return isidentical(root1->left,root2->left) && isidentical(root1->right,root2->right);
}
//subtree
bool issubtree(Node* root,Node* subtree){
    //base case
    if(root==NULL && subtree==NULL){
        return true;
    }else if(root==NULL || subtree==NULL){
        return false;
    }

    if(root->data==subtree->data){
        //identical for subtree
        if(isidentical(root,subtree)){
            return true;
        }
    }

    int isleftsubtree=issubtree(root->left,subtree);
    if(!isleftsubtree){
        return issubtree(root->right,subtree);
    }

    return true;
}

int main(){
    vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root=buildtree(nodes);//1
    // cout<<"root:"<<root->data;

    Node* subroot=new Node(2);
    subroot->left=new Node(4);
    subroot->right=new Node(1);

    cout<<issubtree(root,subroot)<<endl;
    return 0;
}