#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;
void nextgreater(vector<int>&arr,vector<int>&ans){
    stack<int>s;
    int n=arr.size();
    s.push(arr[n-1]);
    ans[n-1]=-1;
    for(int i=n-2;i>=0;i--){
        int curr=arr[i];
        while(!s.empty() && curr>=s.top()){
             s.pop();
        }
        if(s.empty()){
            ans[i]=(-1);
    
        }else{
             ans[i]=s.top();
        }
        s.push(arr[i]);
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    
}
int main(){
   vector<int>arr={6,8,0,1,3};
   vector<int>ans={0,0,0,0,0};
   nextgreater(arr,ans);
    return 0;
}