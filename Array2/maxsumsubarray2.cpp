#include<iostream>
using namespace std;
int printsum(int *arr,int n){
    int maxsum=0;
    for(int st=0;st<n;st++){
        int currsum=0;
        for(int en=st;en<n;en++){
            currsum+=arr[en];
            maxsum=max(maxsum,currsum);
        }
    }
    cout<<"max subarray sum: "<<maxsum;
}
int main(){
    int arr[]={2,-3,6,-5,4,2};
    int n=sizeof(arr)/sizeof(int);
    printsum(arr,n);
    return 0;
}