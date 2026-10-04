#include<iostream>
#include<deque>
#include<queue>
using namespace std;
class Queue{
    deque<int>deq;
public:
    void push(int data){
        deq.push_back(data);
    }
    void pop(){
        deq.pop_front();
    }
    int  front(){
        return deq.front();
    }
    bool empty(){
        return deq.empty();
    }
};
int main(){
    Queue q;
    for(int i=0;i<5;i++){
        q.push(i);
    }
    while (!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    
    return 0;
}