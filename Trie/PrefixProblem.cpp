#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
class Node{
public:
   unordered_map<char,Node*>children;
   bool endofword;
   int freq;
   Node(){
     endofword=false;
   }

};

class Trie{
    Node* root;
public:
    Trie(){
        root=new Node();
        root->freq=-1;
    }
    void insert(string key){
        Node* temp=root;
        for(int i=0;i<key.size();i++){
            if(temp->children.count(key[i])==0){
                temp->children[key[i]]=new Node();
                temp->children[key[i]]->freq=1;

            }else{
                temp->children[key[i]]->freq++;
            }
            temp=temp->children[key[i]];
        }
        temp->endofword=true;
    }
    

    string getprifix(string key){
        Node* temp=root;
        string prifix="";
        for(int i=0;i<key.size();i++){
            prifix+=key[i];
            if(temp->children[key[i]]->freq==1){
                return prifix;
            }
            temp=temp->children[key[i]];

        }
        return prifix;
    }
};


void preefixprob(vector<string>dict){
    Trie t1;
    for(int i=0;i<dict.size();i++){
        t1.insert(dict[i]);
    }

    for(int i=0;i<dict.size();i++){
        cout<<t1.getprifix(dict[i])<<endl;
    }

}
int main(){
    vector<string>dict={"zebra","dog","duck","dove"};
    preefixprob(dict);
    
    return 0;
}