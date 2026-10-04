// Maps are associative containers that store key–value pairs in sorted order using 
// a self-balancing Red-Black Tree. They provide efficient O(log n) time complexity 
// for insertion, deletion, and searching operations.

// Maps do not allow duplicate keys.
// They support ordered traversal and functions like upper_bound() and lower_bound().

#include<iostream>
#include<map>
using namespace std;
int main(){
    //key val 
    map<string,int>m;
    m["china"]=150;
    m["india"]=100;
    m["US"]=10;
    for(pair<string,int>country:m){
        cout<<country.first<<":"<<country.second<<endl;
    }
    // m.erase("US");
    //count 1 present,0 not present
    cout<<m.count("india")<<endl;
    for(pair<string,int>country:m){
        cout<<country.first<<":"<<country.second<<endl;
    }
    return 0;
}
