#include<iostream>
#include<vector>
using namespace std;
bool iszero(const vector<int>&nums){
    for(auto i:nums){
        if(i!=0){
            return false;
        }
    }
    return true;
}
int minZeroArray(vector<int> nums, vector<vector<int>>& queries) {
    int n=queries.size();
    int m=nums.size();
    for(int i=0;i<n;i++){
        int l=queries[i][0];
        int r=queries[i][1];
        int val=queries[i][2];
        
        for(int j=l;j<=r;j++){
            nums[j]=nums[j]-val;
        }
        if(iszero(nums)){
            return i+1;
        }
    }
    return -1;
}
int main(){
    vector<int> nums = {1, 2, 3, 2, 1};

    // Queries in format [l, r, val]
    vector<vector<int>> queries = {
        {0, 1, 1},
        {1, 2, 1},
        {2, 3, 2},
        {3, 4, 1},
        {4, 4, 1}
    };
    cout<<minZeroArray(nums,queries);
     return 0;
}