#include<iostream>
#include<vector>
using namespace std;
int cataMemo(int n,vector<int>&dp){
    if(n==0 || n==1){
        return 1;
    }

    if(dp[n] != -1){
        return dp[n];
    }

    int ans=0;
    for(int i=0;i<n;i++){
        ans+=cataMemo(i,dp)*cataMemo(n-i-1,dp);
    }
    return dp[n]=ans;
}
 int main(){
    int n=7;//nth catalan's number
    vector<int>dp(n+1,-1);
    for(int i=0;i<n;i++){
        cout<<cataMemo(i,dp)<<" ";
    }
    
    return 0;

 }