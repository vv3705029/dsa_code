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


//TOP VIEW
void topview(Node* root){
    queue<pair<Node*,int>>q;//(node,HD)
    unordered_map<int,int>m;//(HD,node->data)//horigontal distance
    q.push(make_pair(root,0));

    while (!q.empty()){
        pair<Node*,int>curr=q.front();
        q.pop();

        Node* currnode=curr.first;
        int currHD=curr.second;
        
        if(m.count(currHD)==0){
            //HD->add in map
            m[currHD]=currnode->data;
        }

        if(currnode->left!=NULL){
            pair<Node*,int>left=make_pair(currnode->left,currHD-1);
            q.push(left);
        }

        if(currnode->right!=NULL){
            pair<Node*,int>right=make_pair(currnode->right,currHD+1);
            q.push(right);
        }
    }
    //print data
        for(auto el:m){
            cout<<el.second<<" ";
        }
}
int main(){
    vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root=buildtree(nodes);//1
    // cout<<"root:"<<root->data;
    topview(root);
    return 0;
}