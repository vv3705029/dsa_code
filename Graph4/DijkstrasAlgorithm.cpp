#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<limits>
using namespace std;
class Edge{
public:
    int v;
    int wt;//weight
    Edge(int v,int wt){
        this->v=v;
        this->wt=wt;
    }
};

 void dijkstraAlgorithm(int src,vector<vector<Edge>>graph,int V){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        //min heap first:dist[v],second:v
        vector<int>dist(V,INT32_MAX);
        
        pq.push(make_pair(0,src));
        dist[src]=0;

        while(pq.size()>0){
            int u=pq.top().first;
            pq.pop();
            
            vector<Edge>edges=graph[u];
            for(Edge e:edges){//e.v,e.wt
                if(dist[e.v]>dist[u]+e.wt){
                    dist[e.v]=dist[u]+e.wt;
                    pq.push(make_pair(e.v,dist[e.v]));
                }
            }

        }

        for(int d:dist){
            cout<<d<<" ";

        }
    }
int main(){
    int V=6;
    vector<vector<Edge>>graph(V);

    graph[0].push_back(Edge(1,2));//1:index, 2:destination, 3:weight
    graph[0].push_back(Edge(2,4));

    graph[1].push_back(Edge(3,7));
    graph[1].push_back(Edge(2,1));

    graph[2].push_back(Edge(4,3));

    graph[3].push_back(Edge(5,1));

    graph[4].push_back(Edge(3,2));
    graph[4].push_back(Edge(5,5));

    dijkstraAlgorithm(0,graph,V);
    return 0;
}