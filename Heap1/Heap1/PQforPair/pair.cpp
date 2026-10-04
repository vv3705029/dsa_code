#include<iostream>
#include<string>
#include<queue>
#include<vector>
using namespace std;
struct ComparePair{
    bool operator() (pair<string,int>&p1,pair<string,int>&p2){
        return p1.second<p2.second;//for maxheap
    }
};
int main(){
    priority_queue<pair<string,int>,vector<pair<string,int>>,ComparePair>pq;//default-maxheap:"first"
    pq.push(make_pair("vikas",34));
    pq.push(make_pair("neha",45));
    pq.push(make_pair("aman",40));
    while(!pq.empty()){
        cout<<pq.top().first<<" : "<<pq.top().second<<endl;
        pq.pop();
    }
    return 0;
}