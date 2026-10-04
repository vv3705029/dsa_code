#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void heapify(int i,vector<int> &arr,int n){
   int left=2*i+1;
   int right=2*i+2;
   int maxi=i;
   if(left<n && arr[left]>arr[maxi]){
       maxi=left;
    }

    if(right<n && arr[right]>arr[maxi]){
        maxi=right;
    }
    swap(arr[i],arr[maxi]);
    if(maxi!=i){
        heapify(maxi,arr,n);
    }
    
}
void heapsort(vector<int> &arr){
    int n=arr.size();

    //step 1:build maxheap
    for(int i=(n/2)-1;i>=0;i--){
        heapify(i,arr,n);
    }

    //step2 :taking els to correct pos
    for(int i=n-1;i>=0;i--){
        swap(arr[0],arr[i]);
        heapify(0,arr,i);
    }
}
int main(){
    vector<int>arr={1,4,2,5,3};
    heapsort(arr);

    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<< " ";
    }

    return 0;
}