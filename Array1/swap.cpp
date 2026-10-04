#include<iostream>
#include<algorithm>
using namespace std;
void print(int *arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int arr[]={2,4,7,8,9,8,1};
    int n=sizeof(arr)/sizeof(int);
    int start=0;
    int end=n-1;
    while(start<end){
        /*int temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;*/
        
        swap(arr[start],arr[end]);
        start++;
        end--;
    }



    // Reverse using inbuilt function
    // reverse(arr,arr+4);
    print(arr,n);
    return 0;
}