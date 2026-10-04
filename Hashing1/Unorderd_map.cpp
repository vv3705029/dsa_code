#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    //key val 
    unordered_map<string,int>m;
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
