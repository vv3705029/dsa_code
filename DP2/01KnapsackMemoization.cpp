#include<iostream>
#include<vector>
using namespace std;

int knapsackMemo(vector<int>val,vector<int>wt,int W,int n,vector<vector<int>>&dp){
    if(W==0 || n==0){
        return 0;
    }

    if(dp[n][W]!=-1){
        return dp[n][W];
    }
    int itemwt=wt[n-1];
    int itemval=val[n-1];
    if(itemwt<=W){//valid
       //include
       int ans1= knapsackMemo(val,wt,W-itemwt,n-1,dp)+itemval;
       //exclude
        int ans2= knapsackMemo(val,wt,W,n-1,dp);

        dp[n][W]= max(ans1,ans2);
    }else{
        //exclusive
        dp[n][W]=knapsackMemo(val,wt,W,n-1,dp);
    }
    return dp[n][W];
}
int main(){
    vector<int>val={15,70,10,40,30};
    vector<int>wt={2,5,1,3,4};
    int W=7;
    int n=val.size();
    vector<vector<int>>dp(n+1,vector<int>(W+1,-1));
    cout<<knapsackMemo(val,wt,W,n,dp)<<"\n";
    
    for(int i=0;i<n+1;i++){
        for(int j=0;j<W+1;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}