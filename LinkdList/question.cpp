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
public:
    Node* head;
    Node* tail;
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
    //find and remove and nth node
    void remove(int n){
        Node* temp=head;
        int length=1;
        while(temp->next!=NULL){
            length+=1;
            temp=temp->next;
        }
        temp=head;
        for(int i=1;i<(length-n);i++){
            temp=temp->next;
        }
        Node* todel=temp->next;
        temp->next=temp->next->next;
        cout<<todel->data<<endl;
        todel->next=NULL;
        
        delete todel;
    }
    
};
//  Question no 2 deleting n node after m node
Node* removennode(Node* head,int n,int m){
        Node* temp=head;
        Node* todelete=NULL;
        for(int i=1;i<m;i++){
            temp=temp->next;
        }
        for(int j=1;j<=n;j++){
            todelete=temp->next;
            temp->next = todelete->next;
            todelete->next=NULL;
            delete todelete;
        }
        return head;
    }
//question no 3 swaping
// Node* swapping(Node* head,int x,int y){
//     Node* temp=head;
//     int count=1;

// }
//Question no 4 odd even liked list
Node* oddeven(Node* head){
    Node* odd=new Node(-1);
    Node* oddhead=odd;
    Node* oddtemp=odd;
    Node* even=new Node(1);
    Node* evenhead=even;
    Node* eventemp=NULL;
    Node* temp=head;
    while (temp!=NULL){
          if((temp->data%2)==0){
            even->next=temp;
            even=oddtemp;
            temp=temp->next;
          }else{
            odd->next=temp;
            temp=temp->next;
          }
    }
    return even;
}

// Node* evenOdd(Node* head){
//     if(!head){
//         return NULL;
//     }
//     Node* odd = new Node(-1);
//     Node* oddtemp=odd;
//     Node* temp = head;
//     while(temp->next!=NULL){
//         if((temp->next->data)%2==0){
//             temp = temp->next;
//         }
//         else{
//             oddtemp->next=temp->next;
//             oddtemp = oddtemp->next;
//             temp->next = oddtemp->next;
//             oddtemp->next=NULL;

//         }
//     }
//     if((head->data %2) !=0){
//         oddtemp->next= head;
//         head= head->next;
//         oddtemp= oddtemp->next;
//        oddtemp->next = NULL; 
//         temp->next = odd->next;
//         return head;
//     }
//     temp->next = odd;
    
//     return head;
    
// }
int main(){
    List l1;
    l1.push_front(8);
    l1.push_front(7);
     l1.push_front(6);
    l1.push_front(5);
    l1.push_front(4);
    l1.push_front(3);
    l1.push_front(2);
    l1.push_front(1);
    l1.display();
    //question no 2
    // l1.head=removennode(l1.head,2,3);
    // l1.display();
    //question no 4
    // l1.head=evenOdd(l1.head);
    l1.head=oddeven(l1.head);
    l1.display();
    return 0;
}