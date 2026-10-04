#include<iostream>
#include<string>
using namespace std;
int binsearch(int arr[],int key,int start,int end){
    
    int mid=(start+end)/2;
    if(arr[mid]==key){
        return mid;
    }
    if(key<arr[mid]){
        return binsearch(arr,key,start,mid-1);
    }
    return binsearch(arr,key,mid+1,end);
}
int main(){
    int arr[]={1,2,3,4,5,6,7};
    int n=sizeof(arr)/sizeof(int);
    cout<<binsearch(arr,4,0,n-1);
    return 0;
}