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
    //BSF CODE
    void BSF(){
    queue<int>q;
    vector<bool>visited(V,false);
    q.push(0);
    visited[0]=true;
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
    g1.addeadge(5,6);
    // g1.print();
    g1.BSF();
    return 0;

}