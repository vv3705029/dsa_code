#include<iostream>
#include<vector>
using namespace std;
class SegmentTree{
    vector<int>tree;//4*n
    int n;
public:
    SegmentTree(vector<int>&arr){
        int n=arr.size();
       tree.resize(4*n);
        buildTree(arr,0,n-1,0);
    }

    void buildTree(vector<int>&arr,int start,int end,int node){
        if(start==end){
            tree[node]=arr[start];
            return;
        }
        int mid=start+(end-start)/2;

        buildTree(arr,start,mid,2*node+1);//left
        buildTree(arr,mid+1,end,2*node+2);//right

        tree[node]=tree[2*node+1]+tree[2*node+2];
    }

    void printTree(){
        for(int i=0;i<tree.size();i++){
            cout<<tree[i]<<" ";
        }
    }

    void updateQuery(int idx,int val,int st,int end,int node){

        if(st==end){
            tree[node]=val;
            return ;
        }
        int mid=st+(end-st)/2;
        if(idx>=st && idx<=mid){//left
            updateQuery(idx,val,st,mid,2*node+1);
        }else{//right
            updateQuery(idx,val,mid+1,end,2*node+2);
        }
        tree[node]=tree[2*node+1]+tree[2*node+2];
    }

    void  updateQueries(int idx,int val){
        return updateQuery(idx,val,0,n-1,0);
    }
};
int main(){
    //Range Sum Queries
    vector<int>arr={1,2,3,4,5,6,7,8};
    SegmentTree t1(arr);
    t1.printTree();
    int idx=0;
    int val=4;
    t1.updateQueries(idx,val);
    t1.printTree();
    return 0;
}