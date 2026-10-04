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
};
int main(){
    Graph g1(5);
    //undirected unweighted
    g1.addeadge(0,1);
    g1.addeadge(1,2);
    g1.addeadge(1,3);
    g1.addeadge(2,3);
    g1.addeadge(2,4);

    g1.print();
    return 0;

}