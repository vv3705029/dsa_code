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
    //CYCLE DETECTION USING KAHNS ALGORITHIMS
    void calcIndegree(vector<int>&indegree){
        for(int u=0;u<V;u++){
            list<int>neighbours=l[u];
            for(int v:neighbours){
                //u-->v
                indegree[v]++;
            }
        }
    }

    bool topologicalsort(){//kahn's algo
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

            list<int>neighbours=l[curr];
            for(int v:neighbours){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                }
            }
        }
        if(q.size()==0){
            return true;
        }
        return false;
    }
};
int main(){
    Graph g1(4);
    //directed Graph
    g1.addeadge(0,2);
    g1.addeadge(2,3);
    g1.addeadge(3,1);
    g1.addeadge(1,2);
    

    g1.print();
    cout<<g1.topologicalsort();//CYCLE DETECTION USING KAHNS ALGORITHIMS
    
    return 0;

}