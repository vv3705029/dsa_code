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
//Kth LEVEL OF A TREE
void helper(Node* root,int level,int currlevel){
     
    if(root==NULL){
        return;
    }

    if(currlevel==level){
        cout<<root->data<<" ";
        return;
    }
    helper(root->left,level,currlevel+1);//left
    helper(root->right,level,currlevel+1);//right

}
void kthlevel(Node* root,int level){
    int currlevel=1;
    helper(root,level,currlevel);
    cout<<endl;
    return;
}

int main(){
    vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root=buildtree(nodes);//1
    // cout<<"root:"<<root->data;
    int level=2;
    kthlevel(root,level);
    return 0;
}