//LONGEST Increasing Subsequence
#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
#include<algorithm>
using namespace std;

int LISTabu(vector<int>arr1,vector<int>arr2){
    int n=arr1.size();
    int m=arr2.size();

    vector<vector<int>>dp(n+1,(vector<int>(m+1,0)));

    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(arr1[i-1]==arr2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }else{
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    return dp[n][m];
}


int main(){
    vector<int>arr1={50,3,10,7,40,80,80};
    unordered_set<int>s;
    for(auto el:arr1){
        s.insert(el);
    }
    vector<int>arr2(s.begin(),s.end());
    sort(arr2.begin(),arr2.end());

    cout<<LISTabu(arr1,arr2);
    return 0;
}