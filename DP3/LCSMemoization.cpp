#include<iostream>
#include<string>
#include<vector>
using namespace std;
int LCSmemo(string str1,string str2,vector<vector<int>>&dp){//O(n*m)
    
    if(str1.size()==0 || str2.size()==0){
        return 0;
    }
     int n=str1.size();
    int m=str2.size();

    if(dp[n][m]!=-1){
        return dp[n][m];
    }

    if(str1[n-1]==str2[m-1]){
        dp[n][m]= 1+LCSmemo(str1.substr(0,n-1),str2.substr(0,m-1),dp);
    }else{
        int ans1=LCSmemo(str1.substr(0,n-1),str2,dp);
        int ans2=LCSmemo(str1,str2.substr(0,m-1),dp);

        dp[n][m]=max(ans1,ans2);
    }

    for(int i=0;i<n+1;i++){
        cout<<i<<" ";
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
    string str2="aceb";
    int n=str1.size();
    int m=str2.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    cout<<LCSmemo(str1,str2,dp);
    return 0;
}