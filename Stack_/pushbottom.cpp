#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;
void pushbottom(stack<int>s,int val){
    if(s.empty()){
        s.push(val);//push at top=push as bottom
        return;

    }
    int temp=s.top();
    s.pop();
    pushbottom(s,val);
    s.push(temp);
}
int main(){
    //STL stack
    stack<int>s1;//In class we use Capital S
    s1.push(3);
    s1.push(2);
    s1.push(1);
    pushbottom(s1,4);
    while(!s1.empty()){//isEmpty()
        cout<<s1.top()<<" ";
        s1.pop();
    }
   
    return 0;
}