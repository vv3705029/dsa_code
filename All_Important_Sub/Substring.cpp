#include<iostream>
#include<vector>
#include<string>
using namespace std;
void substring(string s,vector<string>&temp){
    int n=s.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n+1;j++){
            temp.push_back(s.substr(i,j));
        }
    }
}
int main(){
    string s="abc";
    vector<string>temp;
    substring(s,temp);
    for(auto x:temp){
        cout<<x<<" ";
    }
    return 0;
}