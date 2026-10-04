#include<iostream>
#include<vector>
#include<queue>
using namespace std;
//ITRATIVE 1.Level Order

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

//HEIGHT
int height(Node* root){
    if(root==NULL){
        return 0;
    }
    int leftht=height(root->left);
    int rightht=height(root->right);

    int currht=max(leftht,rightht)+1;

    return currht;
}

 //O(n^2)
int diameter1(Node* root){
    if(root==NULL){
        return 0;
    }
    int currdia=height(root->left)+height(root->right)+1;
    int leftdia=diameter1(root->left);
    int rightdia=diameter1(root->right);

    return max(currdia,max(rightdia,leftdia));
}
pair<int,int> diameter2(Node* root){//O(n)

    if(root==NULL){
        return make_pair(0,0);
    }

     //(diameter,height)
     pair<int,int>leftinfo=diameter2(root->left);//(LD,LH)
     pair<int,int>rightinfo=diameter2(root->right);//(RD,RH)

    int currdiam=leftinfo.second+rightinfo.second+1;
    int finaldiam=max(currdiam,(leftinfo.first,rightinfo.first));
    int finalht=max(leftinfo.second,rightinfo.second)+1;

    return make_pair(finaldiam, finalht);
}

//O(n)

int main(){
    vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root=buildtree(nodes);//1
    // cout<<"root:"<<root->data;
//    cout<<"Diameter:"<<diameter1(root)<<endl;//O(n^2)
   cout<<"Diam:"<<diameter2(root).first<<endl;

   
    return 0;
}