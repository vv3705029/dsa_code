#include<iostream>
using namespace std;
int pointer(int arr[][4],int n,int m){
    cout<<"0 row ptr: "<<arr<<endl;
    cout<<"1 row ptr: "<<arr+1<<endl;

    cout<<"0 row value: "<<*arr<<endl;
}
int main(){
    
    int arr[4][4] = {{10, 20, 30, 40}, {15, 25, 35, 45}, {27, 29, 37, 48}, {32, 33, 39, 50}};
    int n=4,m=4;
    pointer(arr,n, m);
    //T.C=O(nlog(m))
    return 0;
}