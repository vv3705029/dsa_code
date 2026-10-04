#include<iostream>
#include<vector>
using namespace std;

int MCMRec(vector<int>&arr,int i,int j,vector<vector<int>>&dp){//return mincost
    if(i==j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int ans=INT16_MAX;

    for(int k=i;k<j;k++){
        //(i,k)
        int cost1=MCMRec(arr,i,k,dp);
        //(k,j)
        int cost2=MCMRec(arr,k+1,j,dp);
        //curr partition cost
        int currcost=cost1+cost2+(arr[i-1]*arr[k]*arr[j]);
        dp[i][j]=min(ans,currcost);
    }
    for(int x=0;x<i;x++){
        for(int y=0;y<j;y++){
            cout<<dp[x][y]<<" ";
        }
        cout<<"\n";
    }
    return dp[i][j];

}
int main(){
    vector<int>arr={1,2,3,4,3};//n ->n-1 matrices (1,n-1)
    int n=arr.size();
    vector<vector<int>>dp(n,(vector<int>(n,-1)));
    cout<< MCMRec(arr,1,n-1,dp);
   
    return 0;
}