#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;
//create stack using linklist
template<class T>//for decide data type
class Node{
public:
    T data;
    Node* next;
   Node(T val){
     data=val;
     next=NULL;
   }
};
template<class T>
class Stack{
    // list<T>ll;
public:
    Node<T>* head;
    Stack(){
        head=NULL;
    }
    void push(T val){
        //push_front()
        // ll.push_front(val);
        Node<T>* newnode=new Node<T>(val);
        if(head==NULL){
            head=newnode;
        }else{
            newnode->next=head;
            head=newnode;
        }
    }
    void pop(){
        // ll.pop_front();
        //pop_front
        Node<T>* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;

    }
    T top(){
        //return ll.front();
        return head->data;
    }
};
int main(){
    //STL stack
    stack<int>s1;//In class we use Capital S
    s1.push(3);
    s1.push(2);
    s1.push(1);
    while(!s1.empty()){//isEmpty()
        cout<<s1.top()<<" ";
        s1.pop();
    }
   
    return 0;
}