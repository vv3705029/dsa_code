#include<iostream>
#include<string>
#include<vector>
using namespace std;
int LCSmemo(string str1,string str2){//O(n*m)
    int n=str1.size();
    int m=str2.size();

    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
           if(str1[i-1]==str2[j-1]){
               dp[i][j]=dp[i-1][j-1]+1;
           }else{
              dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
           }
        }
    }
    

    for(int i=0;i<n+1;i++){
        cout<<i<<":";
        for(int j=0;j<m+1;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
    return dp[n][m];
}
int main(){
    // string str1="abcdge";
    // string str2="abedg";
    string str1="abcd";
    string str2="acedk";
    
    cout<<LCSmemo(str1,str2);
    return 0;
}