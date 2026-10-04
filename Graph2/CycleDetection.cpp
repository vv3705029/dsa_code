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
    //CYCLE DETECTION IN GRAPH
    bool DFShelper(int src,int parent,vector<bool>&visited){
        visited[src]=true;
        list<int>neighbours=l[src];
        for(int i:neighbours){
            if(!visited[i]){
               if(DFShelper(i,src,visited)){
                   return true;
               }
            }else{
                if(i!=parent){//cycle condition
                    return true;
                }
            }
        }
        return false;
    }
    bool Cycledetection(){
        vector<bool>visited(V,false);
        return DFShelper(0,-1,visited);
    }

    // //print disconnected graph using BSF
    // void BSFhelper(int i,vector<bool>&visited){
    // queue<int>q;
    // q.push(i);
    // visited[i]=true;
    // while(q.size()>0){
    //     int u=q.front();//curr vertex
    //     q.pop();
    //     cout<<u<<" ";
    //     list<int>neighbours=l[u];//u--v

    //     for(int v:neighbours){
    //          if(!visited[v]){
    //             visited[v]=true;
    //             q.push(v);
    //          }
    //     }
    // }
    // }
    // void BSF(){
    //     vector<bool>visited(V,false);
    //     for(int i=0;i<V;i++){
    //         if(!visited[i]){
    //             BSFhelper(i,visited);
                
    //         }
    //     }
    // }
};
int main(){
    Graph g1(5);
    //undirected unweighted
    g1.addeadge(0,2);
    g1.addeadge(0,1);
    g1.addeadge(1,2);
    g1.addeadge(0,3);
    g1.addeadge(3,4);
    
    
    g1.print();
    cout<<g1.Cycledetection();
    return 0;

}