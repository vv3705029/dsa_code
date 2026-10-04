#include<iostream>
#include<vector>
using namespace std;
class DisjointSet{
public:
    int n;
    vector<int>par;
    vector<int>rank;
    DisjointSet(int n){
        this->n=n;
        for(int i=0;i<n;i++){
            par.push_back(i);
            rank.push_back(0);
        }
    }
    int find(int x){
        if(par[x]==x){
            return x;
        }
        return par[x]==find(par[x]);   //path compration
        // return find(par[x]);
    }
    void unionByRnak(int a,int b){
        int parA=find(a);
        int parB=find(b);
        if(rank[parA]==rank[parB]){
            rank[parA]++;
            par[parB]=parA;
        }else if(rank[parA]>rank[parB]){
            par[parB]=parA;
        }else{
            par[parA]=parB;
        }
    }
    void getInfo(){
        for(int i=0;i<n;i++){
            cout<<i<<":"<<par[i]<<","<<rank[i]<<endl;
        }
    }
};
int main(){
    DisjointSet dj(6);
    dj.unionByRnak(0,2);
    cout<<dj.find(2)<<endl;
    dj.unionByRnak(1,3);
    dj.unionByRnak(2,5);
    dj.unionByRnak(0,3);
    cout<<dj.find(3)<<endl;
    dj.unionByRnak(0,4);
    dj.getInfo();
    return 0;
}