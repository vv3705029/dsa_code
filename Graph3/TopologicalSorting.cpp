#include<iostream>
#include<vector>
#include<list>
#include<stack>
using namespace std;
class Graph {
    int V;//Number of vertexs
    list<int>* l;
    // bool isdirected;
public:
    Graph(int V){
        this->V=V;
        l=new list<int>[V];
        // this->isdirected=isdirected;
    }

    void addeadge(int u,int v){//u-->v
        l[u].push_back(v);
        // if(isdirected){
        //     l[v].push_back(u);
        // }
    }

    void print(){
        for(int u=0;u<V;u++){
            list<int>neighbors=l[u];
            cout<<u<<":";
            for(int v:neighbors){
                cout<<v<<" ";
            }
            cout<<endl;
        }
    }
    
    void topologicalSortHelper(int src,vector<bool>&visited,stack<int>&s){//dfs
        visited[src]=true;
        list<int>neghbours=l[src];
        for(int v:neghbours){
            if(!visited[v]){
                topologicalSortHelper(v,visited,s);
            }
        }

        cout<<"vikas"<<endl;
        s.push(src+1);
    }

    void topologicalSort(){//O(E+V)
        vector<bool>visited(V,false);
        stack<int>s;

        for(int i=0;i<V;i++){
            if(!visited[i]){
                topologicalSortHelper(i,visited,s);
            }
        }
        //print stack
        while(!s.empty()){
            cout<<s.top()<<" ";
            s.pop();
        }
    }
    
};
int main(){
    Graph g1(6);
    //directed Graph
    g1.addeadge(5,2);
    g1.addeadge(2,3);
    g1.addeadge(3,1);
    g1.addeadge(5,0);
    g1.addeadge(4,1);
    g1.addeadge(4,0);

    g1.print();
    g1.topologicalSort();
    return 0;

}