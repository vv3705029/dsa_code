#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node* prev;
    Node(int val){
        data=val;
        next=prev=NULL;
    }
};
class DoubleList{
public:
     Node* head;
     Node* tail;
    DoubleList(){
        head=tail=NULL;
    }
    void push_front(int val){
        Node* newnode=new Node(val);
        if(head==NULL){
            head=tail=newnode;
        }else{
            newnode->next=head;
            head->prev=newnode;
            head=newnode;
        }

    }
    void push_back(int val){
        Node* newnode=new Node(val);
        if(head==NULL){
            head=tail=newnode;
        }else{
            tail->next=newnode;
            newnode->prev=tail;
            tail=newnode;
        }
    }
    void pop_front(){
        Node* temp=head;
        head=head->next;
        if(head!=NULL){
            head->prev=NULL;
        }
        temp->next=NULL;
        delete temp;
    }
    void display(){
        if(head==NULL){
            cout<<"No linked list."<<endl;
        }
        while(head!=NULL){
            cout<<head->data<<" ";
            head=head->next;
        }
    }
};
int main(){
    DoubleList ll;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(6);
    ll.push_front(7);
    ll.push_back(10);
    ll.display();
    ll.pop_front();
    ll.display();
    return 0;
}