//Prim's Algorithims
#include<iostream>
#include<vector>
#include<list>
#include<queue>
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

    void primsAlgo(int src){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        //min heap (wt,v)
        vector<bool>mst(V,false);
        pq.push(make_pair(0,src));
        int ans=0;
        while(pq.size()>0){
            int u=pq.top().second;
            int wt=pq.top().first;
            pq.pop();

            if(!mst[u]){
                mst[u]=true;
                ans+=wt;
                list<pair<int,int>>neighbours=l[u];//n.first:v,n.second:weight
                for(auto n:neighbours){
                    pq.push(make_pair(n.second,n.first));
                }
            }

        }

        
    }
};
int main(){
    Graph g1(4);
    //undirected unweighted
    g1.addeadge(make_pair(0,1),10);
    g1.addeadge(make_pair(0,3),30);
    g1.addeadge(make_pair(0,2),15);
    g1.addeadge(make_pair(1,3),40);
    g1.addeadge(make_pair(3,2),50);

    // g1.print();
    g1.primsAlgo(0);
    return 0;

}