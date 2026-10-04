#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main(){
    // priority_queue<int>pq;//max heap
    priority_queue<int,vector<int>,greater<int>>pq;//min heap
    pq.push(5);
    pq.push(20);
    pq.push(10);

    while ((!pq.empty())){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    
    return 0;
}