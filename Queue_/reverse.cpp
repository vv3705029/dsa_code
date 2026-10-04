#include<iostream>
#include<stack>
#include<queue>
using namespace std;
void reverse(queue<int>org){
    stack<int>s;
    while (!org.empty()){
        s.push(org.front());
        org.pop();
    }
    while(!s.empty()){
        org.push(s.top());
        s.pop();
    }
    while(!org.empty()){
        cout<<org.front()<<" ";
        org.pop();
    }
    
}
int main(){
    queue<int>org;
    for(int i=0;i<=5;i++){
        org.push(i);
    }
    reverse(org);
    return 0;
}