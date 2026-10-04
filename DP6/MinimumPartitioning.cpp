#include<iostream>
#include<vector>
using namespace std;

int gitMindiffrance(vector<int>arr){
    int n=arr.size();
    int totSum=0;
    for(int i=0;i<n;i++){
        totSum+=arr[i];
    }

    int W=totSum/2;
    vector<vector<int>>dp(n+1,(vector<int>(W+1,0)));
    for(int i=1;i<n+1;i++){
        for(int j=1;j<W+1;j++){
            if(arr[i-1]<=j){
                dp[i][j]=max(arr[i-1]+dp[i-1][j-arr[i-1]],dp[i-1][j]);
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }

    int group1sum=dp[n][W];
    int group2sum=totSum-group1sum;
    
    for(int i=0;i<n+1;i++){
        for(int j=0;j<W+1;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
    return abs(group1sum-group2sum);
}
int main(){
    vector<int>arr={1,15,3,1};
   
    cout<<gitMindiffrance(arr);
    return 0;
}