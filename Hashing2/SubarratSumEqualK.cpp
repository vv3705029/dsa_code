#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
int largestSubArrat(vector<int>arr,int k){
    unordered_map<int,int>m;
    
    int sum=0;
    int ans=0;

    for(int j=0;j<arr.size();j++){
        sum+=arr[j];
        
        if(sum==k){
            ans++;
        }
        if(m.find(sum-k)!=m.end()){
            ans+=m[sum-k];
        }
        m[sum-k]++;
    }
    
    return ans;
}
int main(){
    vector<int>arr={10,2,-2,-20,10,10,-10};
    int k=-10;
    cout<<largestSubArrat(arr,k);
    return 0;
}
