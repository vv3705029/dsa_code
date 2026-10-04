#include<iostream>
using namespace std;
int selectionsort(int *arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int arr[]={5,4,1,3,2};
    int n=sizeof(arr)/sizeof(int);
    for(int i=0;i<n-1;i++){
        int key=i;
        for(int j=(i+1);j<n;j++){
            if(arr[j]<arr[key]){
                key=j;
            }
        }
        swap(arr[key],arr[i]);
    }
    selectionsort(arr,n);
    return 0;
}