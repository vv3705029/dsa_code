//LONGEST COMMEN SUBSTRING
#include<iostream>
#include<vector>
#include<string>
using namespace std;
int LCSTabu(string str1,string str2){
    int n=str1.size();
    int m=str2.size();
    int ans=0;
    vector<vector<int>>dp(n+1,(vector<int>(m+1,0)));

    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(str1[i-1]==str2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
                ans=max(ans,dp[i][j]);
            }else{
                dp[i][j]=0;
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
    return ans;
}
int main(){
    string str1="abcdefghskuhcksud";
    string str2="abcdedgkjsdgdgsjdghfgjhlk;gjkhgjfhsdgkjlhkgkfjdhfjgklkjdhdyluiytuyjh";

    cout<<LCSTabu(str1,str2);
    return 0;
}