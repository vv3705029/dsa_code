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
    ~Node(){
        
        if(next!=NULL){
            delete next;
            next=NULL;
        }
    
    }
};
class List{
    Node* head;
    Node* tail;
public:
    List(){
        head=NULL;
        tail=NULL;
    }
    ~List(){
     
        if(head!=NULL){
            delete head;
            head=NULL;
        }
        
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
    //insertiong a new element
    void insert(int val,int pos){
        Node* newnode=new Node(val);
        Node* temp=head;
        if(pos==1){
            push_front(val);
            return;
        }
        for(int i=0;i<pos-1;i++){
            if(temp==NULL){
                cout<<"position is invalid.";
            }
            temp=temp->next;
        }
        //now temp is at position pos-1
        
        newnode->next=temp->next;
        temp->next=newnode;
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
    void pop_front(){
        if(head==NULL){
            cout<<"LL is empty"<<endl;
            return;
        }
        Node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }

    void pop_back(){//deleting last element
        if(head==NULL){
            cout<<"list is empty"<<endl;
            return;
        }
        if(head->next==NULL){
            pop_front();
        }
        Node* temp=head;
        while (temp->next->next!=NULL){
            temp=temp->next;
        }
        temp->next=NULL;
        delete temp;//temp=tail's prev
    }
    //searching
    int search(int x){
        if(head==NULL){
            return -1;
        }

         Node* temp=head;
         int count =0;
         while ( temp!=NULL && temp->data!=x ){
                count++;
                temp=temp->next;
         }
         if(temp!=NULL){
            return count;

         }
         return -1;
    }

    //recersive search
    int helper(Node* temp,int key){
        if(temp->data==key){
            return 0;
        } 
        int idx=helper(temp->next,key);
        if(idx== -1){
            return -1;
        }
        return idx+1;
    }
    int recsearch(int key){
        return helper(head,key);
    }
    //revesing an linklist
    void reverse(){
        Node* curr=head;
        Node* prev=NULL;
        while(curr!=NULL){
            Node* next=curr->next;
            curr->next=prev;
            //apdation
            prev=curr;
            curr=next;
        }
        head=prev;
    }
    //find and remove and nth node from end
    void remove(int n){
        // Node* temp=head;
        // int length=1;
        // while(temp->next!=NULL){
        //     length+=1;
        //     temp=temp->next;
        // }
        // temp=head;
        // for(int i=1;i<(length-n);i++){
        //     temp=temp->next;
        // }
        // Node* todel=temp->next;
        // temp->next=temp->next->next;
        // cout<<todel->data<<endl;
        // todel->next=NULL;
        
        // delete todel;
        int count=1;
        Node* temp=head;
        while(temp->next!=NULL){
            count+=1;
            temp=temp->next;
        }
        temp=head;
        for(int i=1;i<(count-n);i++){
            temp=temp->next;
        }
        Node* deletenode=temp->next;
        temp->next=deletenode->next;
        deletenode=NULL;
        delete deletenode;
    }

};
int main(){
    List l1;
    l1.push_front(3);
    l1.push_front(2);
     l1.push_front(1);
    l1.push_back(3);
    l1.push_back(2);
    l1.push_back(1);
    // l1.insert(100,1);
    // l1.pop_front();
    // l1.reverse();
    // l1.remove(3);
    l1.display();
    l1.remove(1);
    l1.display();
    //cout<<l1.search(5)<<endl;
    // cout<<l1.recsearch(2)<<endl;
    // l1.pop_back();
    // l1.reverse();
    return 0;
}