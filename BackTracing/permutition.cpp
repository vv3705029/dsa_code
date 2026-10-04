#include<iostream>
using namespace std;
void permu(string str,string ans){
    int n=str.size();
    if(n==0){
        cout<<ans<<" ";
    }
    for(int i=0;i<n;i++){
        string nextstr=str.substr(0,i)+str.substr(i+1,n-i-1);
        permu(nextstr,ans+str[i]);
    }
}
int main(){
    permu("abc","");
}