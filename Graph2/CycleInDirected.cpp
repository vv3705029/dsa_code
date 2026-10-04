#include<iostream>
#include<vector>
#include<list>
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
    
    bool dircyclehelper(int src,vector<bool>&visited,vector<bool>&recpath){
        visited[src]=true;
        recpath[src]=true;
        list<int>neghbours=l[src];
        for( int v:neghbours){
            if(!visited[v]){
                if(dircyclehelper(v,visited,recpath)){
                    return true;
                }
            }else{
                if(recpath[v]){
                    return true;
                }
            }
        }
        recpath[src]=false;
        return false;
    }

    bool iscycledirected(){
        vector<bool>visited(V,false);
        vector<bool>recpath(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(dircyclehelper(i,visited,recpath)){
                    return true;
                }
            }
        }
        return false;
    }
};
int main(){
    Graph g1(5);
    //directed Graph
    g1.addeadge(1,0);
    g1.addeadge(0,2);
    g1.addeadge(2,3);
    g1.addeadge(3,0);
    g1.addeadge(3,4);


    g1.print();
    cout<<g1.iscycledirected();
    return 0;

}



// To detect a cycle in a directed graph, we use Depth First Search (DFS). 
//If DFS reaches a vertex that is already present in the current DFS path, a cycle exists.
// Using only visited[] is not enough. A vertex may have been visited during 
//an earlier DFS traversal but may not be part of the current DFS path. 
//Therefore, we also keep track of the vertices currently being explored.

// For this, we use two arrays:

// visited[]: Marks vertices that have been visited at least once.
// recStack[]: Marks vertices that are currently present in the DFS recursion path.
// If during DFS we reach a vertex whose recStack[] value is true, a cycle is found. 
//After completely exploring all adjacent vertices of a node, we remove it from the 
//current DFS path by setting recStack[u] = false. This ensures that recStack[] contains
// only the vertices that belong to the current DFS path.