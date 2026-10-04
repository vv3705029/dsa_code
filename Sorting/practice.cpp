#include<iostream>
using namespace std;
void insertionsort(char *arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    char arr[]={'f','b','a','e','c','d'};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=1;i<n;i++){
        int key=i;
        for(int j=0;j<i;j++){
            if(arr[key]>arr[j]){
                swap(arr[key],arr[j]);
            }
        }
    }
    insertionsort(arr,n);
    return 0;
}