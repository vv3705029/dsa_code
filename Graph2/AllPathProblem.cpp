#include<iostream>
#include<vector>
#include<list>
using namespace std;
class Graph {
    int V;//Number of vertexs
    list<int>* l;
    bool dir;
public:
    Graph(int V,bool dir=true){
        this->V=V;
        l=new list<int>[V];
        this->dir=dir;
    }

    void addeadge(int u,int v){
        l[u].push_back(v);
        if(dir){
            l[v].push_back(u);
        }
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
    

    void pathhelper(int src,int dest,vector<bool>&visited,string path){//O(V+E)
        if(src==dest){
            for(int i=0;i<path.size();i++){
                cout<<path[i]<<" ";
            }
            cout<<dest<<endl;
            return;
        }

        visited[src]=true;
        path+=to_string(src);
        list<int>neighbours=l[src];

        for(int v:neighbours){
            if(!visited[v]){
                pathhelper(v,dest,visited,path);
            }
        }

        path=path.substr(0,path.size()-1);
        visited[src]=false;
    }


    void printAllpath(int src,int dest){
        vector<bool>visited(V,false);
        string path="";
        pathhelper(src,dest,visited,path);

    }
};
int main(){
    Graph g1(6,false);
    //undirected unweighted
    g1.addeadge(0,3);
    g1.addeadge(2,3);
    g1.addeadge(3,1);
    g1.addeadge(4,0);
    g1.addeadge(4,1);
    g1.addeadge(5,0);
    g1.addeadge(5,2);
    
    g1.print();
    g1.printAllpath(5,1);
    return 0;

}