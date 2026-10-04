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
            cout<<"Their is no element.";
        }
        Node* newnode=head;
        while(newnode!=NULL){
            cout<<newnode->data<<" ";
            newnode=newnode->next;
        }
    }
};
 //merge sort by linked list
    Node* splitmid(Node* head){
        Node* slow=head;
        Node* fast=head;
        Node* prev=slow;
        while(fast!=NULL && fast->next!=NULL){
                prev=slow;
                slow=slow->next;
                fast=fast->next;
        }
        prev->next=NULL;
        return slow;
    }
    Node* merge(Node* left,Node* right){
        List ans;
        Node* i=left;
        Node* j=right;
        while(i!=NULL && j!=NULL){
               if(i->data <= j->data){
                  ans.push_back(i->data);
                  i=i->next;
               }else{
                ans.push_back(j->data);
                j=j->next;
               }
        }
        while (i!=NULL)
        {
            ans.push_back(i->data);
            i=i->next;
        }
        while (j!=NULL)
        {   
            ans.push_back(j->data);
            j=j->next;
        }
        return ans.head;
        
    }
    Node* mergesort(Node* head){
        if(head==NULL || head->next==NULL){
        return head;
    }
        Node* righthalf=splitmid(head);
        Node* left=mergesort(head);
        Node*right=mergesort(righthalf);
        merge(left,right);//for adding two sorted linkedlist
    }

    //nth node from end
    Node* helper(Node* head,int x){
        if(head==NULL){
            return head;
        }
        int size=0;
        Node* temp=head;
        while(temp!=NULL){
            size++;
            temp=temp->next;
        }
        temp=head;
        for(int i=0;i<(size-x-1);i++){
            temp=temp->next;
        }
        Node* delnode=temp->next;
        temp->next=delnode->next;
        return head;

    }
    Node* delnthnodefromend(int x){
        Node* head;
        return helper(head,x);
    }

int main(){
    List ll;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_front(4);
    ll.push_back(9);
    ll.display();
    // ll.head=mergesort(ll.head);
    // cout<<endl;
    delnthnodefromend(3);
    ll.display();
    return 0;
}