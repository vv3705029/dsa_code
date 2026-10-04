#include<iostream>
using namespace std;
bool  issorted(int arr[],int n,int i){
    if(i==n-1){
        return true;
    }
    if(arr[i]>arr[i+1]){
        return false;
    }
    return issorted(arr,n,i+1);
}
int main(){
    int arr1[]={1,2,34,454};
    int n=sizeof(arr1)/sizeof(int);
    cout<<issorted(arr1,n,0)<<endl;
    return 0;
}