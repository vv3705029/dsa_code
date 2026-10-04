#include<iostream>
#include<unordered_set>
#include<set>
#include<vector>
using namespace std;
void Union(vector<int>arr1,vector<int>arr2){
    unordered_set<int>s;
    for(int el: arr1){
        s.insert(el);
    }
    for(int el: arr2){
        s.insert(el);
    }  

    for(int el: s){
        cout<<el<<" ";
    }
}

void Intersection(vector<int>arr1,vector<int>arr2){
    unordered_set<int>s;
    for(int el: arr1){
        s.insert(el);
    }
    for(int el: arr2){
        if(s.find(el)!=s.end()){
            //found
            cout<<el<<" ";
            s.erase(el);
        }
    }
}
int main(){
    vector<int>arr1={7,3,3,9};
    vector<int>arr2={6,3,9,2,9,4};
    Union(arr1,arr2);//4 2 7 3 9 6
    cout<<endl;
    Intersection(arr1,arr2);//3 9
    return 0;
}
