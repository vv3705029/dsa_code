#include<iostream>
using namespace std;
void substring(string str,string subset,int n){
    if(str.size()==0){
        cout<<subset<<" ";
        return ;
    }
    substring(str.substr(1,n-1),subset+str[0],n);
    substring(str.substr(1,n-1),subset,n);
}
int main(){
    string str="abc";
    string subset="";
    substring(str,subset,str.size());
}