#include<iostream>
#include<deque>
using namespace std;
int main(){
    deque<int>q;
    q.push_back(1);
    q.push_back(5);
    q.push_front(3);
    q.pop_back();
    while (!q.empty()){
        cout<<q.front()<<" ";
        q.pop_front();
    }
    
    return 0;
     
}