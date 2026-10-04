#include<iostream>
using namespace std;
int search(int arr[],int si,int ei,int tar){
    if(si>ei){
        return -1;
    }
    int mid=(si+ei)/2;
    if(arr[mid]==tar){
        return mid;
    }
    if(arr[si]<=arr[mid]){
        //l1
        if(arr[si]<=tar && tar<=arr[mid]){
            //left half
            return search(arr,si,mid-1,tar);
        }
        else{
            return search(arr,mid+1,ei,tar);
        }
    }
    else{
        //l2
        if(arr[mid]<=tar && tar<=arr[ei]){
            return search(arr,mid+1,ei,tar);//right half
        }else{
            return search(arr,si,mid-1,tar);
        }
    }
}
int main(){
    int arr[]={4,5,6,7,0,1,2};
    int n=sizeof(arr)/sizeof(int);
    cout<<search(arr,0,n-1,1);
    return 0;
}