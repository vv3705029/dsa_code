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
    

    //BIPARTITE GRAPH APPROCAH 1
    bool isBipartite(){
        queue<int>q;
        vector<bool>visited(V,false);
        vector<int>color(V,-1);
        q.push(0);
        color[0]=0;

        while(q.size()>0){
            int curr=q.front();
            q.pop();
            list<int>neighbours=l[curr];

            for(int v:neighbours){
                if(!visited[v]){
                    visited[v]=true;
                    color[v]=!color[curr];
                    q.push(v);
                }else{
                    if(color[v]==color[curr]){
                        return false;
                    }
                }
            }
        }

        return true;
    }

    //BIPARTITE GRAPH APPROCAH 2
    bool isBipartite1(){
        queue<int>q;
        vector<int>color(V,-1);
        q.push(0);
        color[0]=0;

        while(q.size()>0){
            int curr=q.front();
            q.pop();
            list<int>neighbours=l[curr];

            for(int v:neighbours){
                if(color[v]==-1){//UVVISITED
                    color[v]=!color[curr];
                    q.push(v);
                }else{
                    if(color[v]==color[curr]){
                        return false;
                    }
                }
            }
        }

        return true;
    }
};
int main(){
    Graph g1(5);
    Graph g2(4);
    //undirected unweighted
    g1.addeadge(0,1);
    g1.addeadge(0,2);
    g1.addeadge(1,3);
    g1.addeadge(3,4);
    g1.addeadge(4,2);

    // g1.print();
    cout<<g1.isBipartite1()<<endl;

    g2.addeadge(0,1);
    g2.addeadge(1,3);
    g2.addeadge(3,2);
    g2.addeadge(0,2);
    g2.print();
    cout<<g2.isBipartite1()<<endl;
    return 0;

}