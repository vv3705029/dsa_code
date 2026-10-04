#include<iostream>
using namespace std;
int insertionsort(int *arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int arr[]={5,4,1,3,2};
    int n=sizeof(arr)/sizeof(int);
    for(int i=1;i<n;i++){
        int key=i;
        for(int j=0;j<i;j++){
            if(arr[key]<arr[j]){
                swap(arr[key],arr[j]);
            }
        }
        insertionsort(arr,n);
        cout<<endl;
    }
    insertionsort(arr,n);
    return 0;
}