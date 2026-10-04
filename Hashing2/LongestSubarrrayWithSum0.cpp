#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
int largestSubArrat(vector<int>arr){
    unordered_map<int,int>m;
    int sum=0;
    int maxlen=0;
    for(int j=0;j<arr.size();j++){
        sum+=arr[j];
        if(m.count(sum)==0){
            m[sum]=j;
        }else{
           int len=j-m[sum];
           maxlen=max(maxlen,len);
        }
    }
    return maxlen;
}
int main(){
    vector<int>arr={15,-2,2,-8,1,7,10};
    cout<<largestSubArrat(arr);
    return 0;
}
