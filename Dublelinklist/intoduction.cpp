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
class List{
public:
    Node* head;
    Node* tail;
    List(){
        head=NULL;
        tail=NULL;
    }
    void push_front(int val){
        Node* newnode=new Node(val);//dynamic
        if(head==NULL){
            head=tail=newnode;
        }else{
            newnode->next=head;
            head=newnode;
        }
    }

    void push_back(int val){
        Node* newnode=new Node(val);
        if(head==NULL){
            head=tail=newnode;
        }else{
            tail->next=newnode;
            tail=newnode;
        }
    }
    void display(){
        if(head==NULL){
            return;
        }
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl; 
    }
    //detect a cycle loop in  ll
    bool iscycle(Node* head){
        Node* slow=head;
        Node* fast=head;
        while (fast!=NULL && fast->next!=NULL){
            slow=slow->next;//=1
            fast=fast->next->next;

             if(slow==fast){
            cout<<"cycle exist"<<endl;
            return true;
            }
        }
        cout<<"cycle does not exist"<<endl;
        return false;
    }
    //remove cycle
    void removecycle(Node* head){
        //detect cycle
        Node* slow=head;
        Node* fast=head;
        bool isCycle=false;
        while (fast!=NULL && fast->next!=NULL){
            slow=slow->next;//=1
            fast=fast->next->next;

            if(slow==fast){
            cout<<"cycle exist"<<endl;
            isCycle=true;
            break;
            }
        }
        if(!isCycle){
            cout<<"Cycle does not exist"<<endl;
            return;
        }
        slow=head;
        if(slow==fast){//special case:if tail is directly connected with head
             while (fast->next != slow)
             {
                fast=fast->next;
             }
             fast->next=NULL;
             
        }else{
            Node* prev=fast;
            while(slow != fast){
                 slow=slow->next;
                 prev=fast;
                 fast=fast->next;
            };
            prev->next=NULL;
            delete prev;
        }
    }

};
int main(){
    List l1;
    l1.push_front(4);
    l1.push_front(3);
    l1.push_front(2);
    l1.push_front(1);
    l1.tail->next=l1.head;
    l1.iscycle(l1.head);
    // l1.removecycle(l1.head);
    // l1.display();
    return 0;
}