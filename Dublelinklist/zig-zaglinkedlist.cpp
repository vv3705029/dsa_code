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
//merge sort
Node* splitmid(Node* head){
     Node* slow=head;
     Node* fast=head;
     Node* prev=slow;
     while(fast!=NULL && fast->next!=NULL){
        prev=slow;
        slow=slow->next;
        fast=fast->next;
     }
     if(prev!=NULL){
        prev->next=NULL;//split at
     }
     return slow;

     
}
Node* merge(Node* left,Node* right){
    List ans;
    Node* i=left;
    Node* j=right;
    while(i != NULL && j != NULL){
        if((i->data)<=(j->data)){
            ans.push_back(i->data);
            i=i->next;
        }else{
            ans.push_back(j->data);
            j=j->next;
        }
    }
    while(i != NULL){
        ans.push_back(i->data);
            i=i->next;
    }
    while(j != NULL){
        ans.push_back(j->data);
        j=j->next;
    }
    return ans.head;
    
}
Node* reverse(Node* head){
    Node* prev=NULL;
    Node*curr=head;
    Node* next=NULL;
    while (curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;//prev is head od reverse
}
Node*  zigzag(Node* head){
    Node* righthead=splitmid(head);
    Node* rightheadrev=reverse(righthead);
    Node* left=head;
    Node* right=rightheadrev;
    Node* tail=NULL;
    while (left!=NULL &&right!=NULL){
        Node* nextleft=left->next;
        Node* nextright=right->next;
        left->next=right;
        right->next=nextleft;

        tail=right;

        left=nextleft;
        right=nextright;
    }
    if(right!=NULL){
        tail->next=right;
    }
    return head;
}
int main(){
    List l1;
    l1.push_front(6);
    l1.push_front(3);
    l1.push_front(9);
    l1.push_front(1);
    l1.push_back(4);
    l1.display();
    l1.head=zigzag(l1.head);
    l1.display();
    return 0;
}