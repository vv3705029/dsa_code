#include<iostream>
#include<vector>
using namespace std;

int MCMRec(vector<int>&arr,int i,int j){//return mincost
    if(i==j){
        return 0;
    }
    int ans=INT16_MAX;

    for(int k=i;k<j;k++){
        //(i,k)
        int cost1=MCMRec(arr,i,k);
        //(k,j)
        int cost2=MCMRec(arr,k+1,j);
        //curr partition cost
        int currcost=cost1+cost2+(arr[i-1]*arr[k]*arr[j]);
        ans=min(ans,currcost);
    }
    return ans;

}
int main(){
    vector<int>arr={1,2,3,4,3};//n ->n-1 matrices (1,n-1)
    int n=arr.size();
    cout<< MCMRec(arr,1,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
   
    return 0;
}