#include<iostream>
#include<vector>
using namespace std;
//create stack using vector
template<class T>//vector dicide 
class Stack{
public:
    vector<T>vec;
    void push(int val){//O(1)
        vec.push_back(val);
    };
    void pop(){
        if(isempty()){
            cout<<"stack is empty"<<endl;
            return ;
        }
        vec.pop_back();
    }
    T top(){
        // if(isempty()){
        //     cout<<"stack is empty."<<endl;
        //     return -1;
        // }
        int lastidx=vec.size()-1;
        return vec[lastidx];
    }
    bool isempty(){
        return vec.size()==0;
    }
    void print(){
        for(int i=0;i<vec.size();i++){
            cout<<vec[i]<<" ";
        }
        cout<<endl;
    }

};
int main(){
    Stack<int> s;
    s.push(3);
    s.push(2);
    s.push(9);
    s.print();
    while (!s.isempty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    // s.print();
    return 0;
}