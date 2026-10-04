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
    
    return 0;

}