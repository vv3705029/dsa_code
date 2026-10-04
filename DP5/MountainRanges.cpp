#include<iostream>
#include<vector>
using namespace std;
int MountanRanges(int n){
    vector<int>dp(n+1,0);
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        for(int j=0;j<i;j++){
            dp[i]+=dp[j]*dp[i-j-1];
        }
       
    }
    return dp[n];
}
 int main(){
    int n=3;//nth catalan's number
    cout<<MountanRanges(n);
    
    return 0;

 }