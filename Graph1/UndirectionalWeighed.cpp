#include<iostream>
#include<vector>
#include<list>
using namespace std;
class Graph {
    int V;//Number of vertexs
    list<pair<int,int>>* l;
public:
    Graph(int V){
        this->V=V;
        l=new list<pair<int,int>>[V];
    }

    void addeadge(pair<int,int>t,int weight){//u,v
       l[t.first].push_back(make_pair(t.second,weight));
       l[t.second].push_back(make_pair(t.first,weight));
    }

    void print(){
        for(int u=0;u<V;u++){
            list<pair<int,int>>neighbors=l[u];
            cout<<u<<":"<<"[";
            for(pair<int,int> v:neighbors){
                cout<<"("<<v.first<<","<<v.second<<")"<<",";
            }
            cout<<"]"<<endl;
        }
    }
};
int main(){
    Graph g1(5);
    //undirected unweighted
    g1.addeadge(make_pair(0,1),5);
    g1.addeadge(make_pair(1,2),1);
    g1.addeadge(make_pair(1,3),3);
    g1.addeadge(make_pair(2,3),1);
    g1.addeadge(make_pair(2,4),2);
    g1.print();
    return 0;

}