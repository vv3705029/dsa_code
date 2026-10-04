#include<iostream>
using namespace std;
int print(int *arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int bubble(int *arr,int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<(n-i-1);j++){
              if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
              }
        }
    }
    print(arr,n);
}
int main(){
    int arr[]={1,4,7,5};
    int n=sizeof(arr)/sizeof(int);
    bubble(arr,n);
    return 0;
}

//time complexcity O(n^2)