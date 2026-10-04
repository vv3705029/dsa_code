#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
class Node{
public:
   unordered_map<char,Node*>children;
   bool endofword;
   Node(){
     endofword=false;
   }

};

class Trie{
    Node* root;
public:
    Trie(){
        root=new Node();
    }
    void insert(string key){
        Node* temp=root;
        for(int i=0;i<key.size();i++){
            if(temp->children.count(key[i])==0){
                temp->children[key[i]]=new Node();

            }
            temp=temp->children[key[i]];
        }
        temp->endofword=true;
    }

    bool search(string key){
        Node* temp=root;
        for(int i=0;i<key.size();i++){
            if(temp->children.count(key[i])){
                temp=temp->children[key[i]];
            }else{
                return false;
            }
        }
        return true;
    }
};

bool startwithproblem(vector<string>words,string key){
    Trie t1;
    for(int i=0;i<words.size();i++){
        t1.insert(words[i]);
    }

    return t1.search(key);
}
int main(){
    vector<string>words={"apple","app","mango","man","women"};
    
    cout<<startwithproblem(words,"man");
    return 0;
}