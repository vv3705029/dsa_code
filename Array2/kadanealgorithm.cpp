#include<iostream>
using namespace std;
int printsum(int *arr,int n){
    int maxsum=INT8_MIN;
    int currsum=0;
    for(int i=0;i<n;i++){
       currsum=max(arr[i],arr[i]+currsum);
       maxsum=max(maxsum,currsum);
       
    }
    cout<<"max subarray sum: "<<maxsum;
}
int main(){
    // int arr[]={2,3,-8,7,-1,2,3};
    int arr[]={-2,-1};
    int n=sizeof(arr)/sizeof(int);
    printsum(arr,n);
    return 0;
}