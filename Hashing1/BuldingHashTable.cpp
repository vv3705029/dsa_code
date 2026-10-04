#include<iostream>
using namespace std;
class Node{
public:
     string key;
     int val;
     Node* next;
     Node(string key,int val){
        this->key=key;
        this->val=val;
        next=NULL;
     }
     ~Node(){
        if(next!=NULL){
            delete next;
        }
     }
};

class HashTable{
    int totsize;//capactiy
    int currsize;//
    Node** table;
    //Hashfunction convert key into index

    int Hashfunction(string key){
        int idx=0;

        for(int i=0;i<key.length();i++){
            idx=idx+(key[i]*key[i])%totsize;
        }

        return idx%totsize;
    }

    //rehashing
    void rehash(){
        Node** oldtable=table;
        int oldsize=totsize;

        totsize=2*totsize;
        currsize=0;
        table=new Node*[totsize];

        for(int i=0;i<totsize;i++){
            table[i]=NULL;
        }
        //copy old value
        for(int i=0;i<oldsize;i++){
            Node* temp=oldtable[i];
            while(temp!=NULL){
                insert(temp->key,temp->val);//call insert function
                temp=temp->next;
            }
            if(oldtable[i]!=NULL){
                delete oldtable[i];
            }
        }
        delete[] oldtable;
    }
public:
    HashTable(int size){
        totsize=size;
        currsize=0;

        table=new Node*[totsize];

        for(int i=0;i<totsize;i++){
            table[i]=NULL;
        }

    }
    //Insert function
    void insert(string key,int val){//O(1)
        int idx=Hashfunction(key);

        Node* newnode=new Node(key,val);

        newnode->next=table[idx];
        table[idx]=newnode;

        currsize++;

        //ReHashing
        double lamdba=currsize/(double)totsize;
        if(lamdba>1){
            rehash();//O(n)
        }
    }
     //searching
    int  search(string key){
         int idx=Hashfunction(key);

         Node* temp=table[idx];
         while (temp!=NULL){
            if(temp->key==key){
                return temp->val;
            }
            temp=temp->next;
         }

         return -1;
         
    }
    //print hashtable
    void print(){
        for(int i=0;i<totsize;i++){
            cout<<"idx:"<<i<<"->";
            if(table[i] != NULL){
                Node* temp = table[i];
                while(temp!=NULL){
                cout<<"("<<temp->key<<": "<<temp->val<<")";
                temp=temp->next;
            }
            }
            else{
                cout<<-1;
            }
            
            cout<<endl;
            
        }
    }
    //remove
    void remove(string key){
         int idx=Hashfunction(key);

         Node* temp=table[idx];
         Node* prev=temp;

         while(temp!=NULL){
            if(temp->key==key){
                if(prev==temp){
                    table[idx]=temp->next;
                }else{
                    prev->next=temp->next;
                }
                break;
            }
            prev=temp;
            temp=temp->next;
         }

    }

};
int main(){
    HashTable h1(5);

    h1.insert("india",150);
    h1.insert("china",100);
    h1.insert("US",50);
    h1.insert("napel",150);

    // cout<<h1.search("india");
    h1.remove("india");
    h1.print();
    return 0;
}