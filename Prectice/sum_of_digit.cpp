#include<iostream>
using namespace std;
int main(){
    string s="12chRc62";
    int n=s.size();
    int sum=0;
    for(int i=0;i<n;i++){
        if(isdigit(s[i])){
            sum+=(s[i]-'0');
        }
    }
    cout<<"Sum : "<<sum;
    return 0;
}