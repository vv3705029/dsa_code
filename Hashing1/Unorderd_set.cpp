#include<iostream>
#include<unordered_set>
#include<set>
using namespace std;
//set is same unordered_set 
int main(){
    //key val 
    // unordered_set<int>s;
    set<int>s;
    s.insert(1);
    s.insert(3);
    s.insert(4);
    s.insert(5);
    s.insert(3);
    s.insert(3);

    // cout<<s.size()<<endl;
    // s.erase(3);
    // if(s.find(3)!=s.end()){//s.find if not exist return s.end
    //     cout<<"exist"<<endl;
    // }else{
    //     cout<<"Not esist"<<endl;
    // }

    //print
    for(auto el:s){
        cout<<el<<",";
    }
    return 0;
}
