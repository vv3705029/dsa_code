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
        return temp->endofword;
    }
};


bool helper(Trie &t1,string key){
    if(key.size()==0){
        return true;
    }
    for(int i=0;i<key.size();i++){
        string first=key.substr(0,i+1);
        string second =key.substr(i+1);

        if(t1.search(first) && helper(t1,second)){
            return true;
        }
    }
}
bool wordbreak(vector<string>dict,string key){
    Trie t1;
    for(int i=0;i<dict.size();i++){
        t1.insert(dict[i]);
    }
    
    return helper(t1,key);
}

int main(){
    vector<string>dict={"i","like","sam","samsung","mobile","ice"};
    cout<<wordbreak(dict,"ilikesam")<<endl;
    
    
    return 0;
}