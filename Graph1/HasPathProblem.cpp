#include<iostream>
#include<vector>
#include<list>
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
    
    bool haspathhelper(int src,int dest,vector<bool>&visited){
        if(src==dest){
            return true;
        }

        visited[src]=true;
        list<int>neihbours=l[src];

        for(int v:neihbours){
            if(!visited[v]){
                if(haspathhelper(v,dest,visited)){
                    return true;
                }
            }
        }

        return false;
    }
    bool HasPath(int  src,int dest){
        vector<bool>visited(7,false);
        return haspathhelper(src,dest,visited);
    }
};
int main(){
    Graph g1(7);
    //undirected unweighted
    g1.addeadge(0,1);
    g1.addeadge(0,2);
    g1.addeadge(1,3);
    g1.addeadge(3,4);
    g1.addeadge(2,4);
    g1.addeadge(3,5);
    g1.addeadge(4,5);
    // g1.addeadge(5,6);

    // g1.print();
    cout<<g1.HasPath(0,3);
    return 0;

}