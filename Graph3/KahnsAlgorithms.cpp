//KAHNS ALGORITMS ALSO USE FOR TOPOLOGICLA SORTING
#include<iostream>
#include<vector>
#include<list>
#include<stack>
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

    void addeadge(int u,int v){//u-->v
        l[u].push_back(v);
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
    
    void topologicalSortHelper(int src,vector<bool>&visited,stack<int>&s){//dfs
        visited[src]=true;
        list<int>neghbours=l[src];
        for(int v:neghbours){
            if(!visited[v]){
                topologicalSortHelper(v,visited,s);
            }
        }

        s.push(src);
    }

    void topologicalSort(){//O(E+V)
        vector<bool>visited(V,false);
        stack<int>s;

        for(int i=0;i<V;i++){
            if(!visited[i]){
                topologicalSortHelper(i,visited,s);
            }
        }
        //print stack
        while(!s.empty()){
            cout<<s.top()<<" ";
            s.pop();
        }
    }
    
    //TOPOLOGICAL  SORTING USING KAHNS ALGORITHIMS
    void calcIndegree(vector<int>&indegree){
        for(int u=0;u<V;u++){
            list<int>neighbours=l[u];
            for(int v:neighbours){
                //u-->v
                indegree[v]++;
            }
        }
    }

    void topologicalsort2(){//kahn's algo
        vector<int>indegree(V,0);
        calcIndegree(indegree);
        queue<int>q;
        //0 indegree nodes --> starting point
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        while(q.size()>0){
            int curr=q.front();
            q.pop();
            cout<<curr<<" ";

            list<int>neighbours=l[curr];
            for(int v:neighbours){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                }
            }
        }
        cout<<endl;
    }
};
int main(){
    Graph g1(6);
    //directed Graph
    g1.addeadge(5,2);
    g1.addeadge(2,3);
    g1.addeadge(3,1);
    g1.addeadge(5,0);
    g1.addeadge(4,1);
    g1.addeadge(4,0);

    g1.print();
    g1.topologicalsort2();
    g1.topologicalsort2();
    return 0;

}