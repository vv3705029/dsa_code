#include<iostream>
using namespace std;
class Node{
public:
     int data;
     Node* next;
     Node(int val){
        data=val;
        next=NULL;
     }
};
class Queue{
    Node* head;
    Node* tail;
public:
    Queue(){
        head=NULL;
        tail=NULL;
    }//pushback
    void push(int val){
        Node* newnode=new Node(val);
        if(head==NULL){
            head=tail=newnode;
        }else{
            tail->next=newnode;
            tail=newnode;
        }
    } 
    //pop_front
    void pop(){
        if(empty()){
            cout<<"queue is empty"<<endl;
            return;
        }
        Node* temp=head;
        head=head->next;
        temp=NULL;
        delete temp;
    }
    //front for head
    int front(){
         if(empty()){
            cout<<"queue is empty"<<endl;
            return -1;
        }
        return head->data;
    }

    //
    bool empty(){
        return head==NULL;
    }
    //display linklist
    // void print(){
    
    //     if(head==NULL){
    //         return ;

    //     }
    //     Node* temp=head;
    //     while(temp!=NULL){
    //         cout<<temp->data<<" ";
    //         temp=temp->next;
    //     }
    // }
};
int main(){
    Queue q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);
    while(!q1.empty()){
        cout<<q1.front()<<" ";
        q1.pop();
    }
    // q1.print();
    return 0;
}
