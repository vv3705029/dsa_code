#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;
class Graph {
    int V;//Number of vertexs
    list<int>* l;
public:
    Graph(int V){
        this->V=V;
        l=new list<int>[V];
    }

    void addeadge(int u,int v){
        l[u].push_back(v);
        l[v].push_back(u);
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
    //print disconnected graph using DFS
    void DFShelper(int u,vector<bool>&visited){
        cout<<u<<" ";
        visited[u]=true;
        list<int>neighbours=l[u];
        for(int v:neighbours){
            if(!visited[v]){
              DFShelper(v,visited);
            }
        }
    }
    void DFS(){
        vector<bool>visited(10,false);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                DFShelper(i,visited);//starting point=i
            }
        }
    }

    // //print disconnected graph using BSF
    void BSFhelper(int i,vector<bool>&visited){
    queue<int>q;
    q.push(i);
    visited[i]=true;
    while(q.size()>0){
        int u=q.front();//curr vertex
        q.pop();
        cout<<u<<" ";
        list<int>neighbours=l[u];//u--v

        for(int v:neighbours){
             if(!visited[v]){
                visited[v]=true;
                q.push(v);
             }
        }
    }
    }
    void BSF(){
        vector<bool>visited(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                BSFhelper(i,visited);
                
            }
        }
    }
};
int main(){
    Graph g1(10);
    //undirected unweighted
    g1.addeadge(0,2);
    g1.addeadge(2,5);
    g1.addeadge(1,6);
    g1.addeadge(6,4);
    g1.addeadge(4,9);
    g1.addeadge(4,3);
    g1.addeadge(3,8);
    g1.addeadge(3,7);
    
    g1.print();
    
    g1.DFS();
    cout<<endl;
    g1.BSF();
    return 0;

}