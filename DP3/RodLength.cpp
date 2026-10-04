#include<iostream>
#include<vector>
using namespace std;
int maxProfit(vector<int>prices,vector<int>length,int rodlen){
    int n=length.size();
    vector<vector<int>>dp(n+1,(vector<int>(rodlen+1,0)));
    for(int i=1;i<n+1;i++){
        for(int j=1;j<rodlen+1;j++){
            if(length[i-1]<=j){//valid
                dp[i][j]=max(prices[i-1]+dp[i][j-length[i-1]],dp[i-1][j]);
            }else{//invalid
                dp[i][j]=dp[i-1][j];
            }
        }

    }
    for(int i=0;i<n+1;i++){
        cout<<i<<":";
        for(int j=0;j<rodlen+1;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
    return dp[n][rodlen];
}
int main(){
    vector<int>prices={1,5,8,9,10,17,17,20};
    vector<int>length={1,2,3,4,5,6,7,8};
    int rodlen=8;
    cout<<maxProfit(prices,length,rodlen);
    return 0;
}