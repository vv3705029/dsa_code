#include<iostream>
#include<algorithm>
using namespace std;
void printarr(int *arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
}
int main(){
    int arr[]={2,10,8,4,3};
    int n=sizeof(arr)/sizeof(int);
    int copyarr[n];
    for(int i=0;i<n;i++){
        int j=n-i-1;
        copyarr[i]=arr[j];
    }
    for(int i=0;i<n;i++){
        arr[i]=copyarr[i];
    }
    // reverse(arr,arr+n);
    printarr(arr,n);
    return 0;
}