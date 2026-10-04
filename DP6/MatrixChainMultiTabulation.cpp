#include<iostream>
#include<vector>
using namespace std;

int MCMTabu(vector<int>&arr){//return mincost
    int n=arr.size();
    vector<vector<int>>dp(n,(vector<int>(n,-1)));
    //initilization
    for(int i=0;i<n;i++){
        dp[i][i]=0;
    }
    //bottom up fill
    for(int len=2;len<n;len++){
        for(int i=1;i<=n-len;i++){
            int j=i+len-1;
            dp[i][j]=INT16_MAX;
            for(int k=i;k<j;k++){
                int cost1=dp[i][k];
                int cost2=dp[k+1][j];

                int currcost=cost1+cost2+(arr[i-1]*arr[k]*arr[j]);

                dp[i][j]=min(currcost,dp[i][j]);
            }
        }
    }
   
    for(int x=0;x<n;x++){
        for(int y=0;y<n;y++){
            cout<<dp[x][y]<<" ";
        }
        cout<<"\n";
    }
    return dp[1][n-1];

}
int main(){
    vector<int>arr={1,2,3,4,3};//n ->n-1 matrices (1,n-1)
    cout<<MCMTabu(arr);
   
    return 0;
}