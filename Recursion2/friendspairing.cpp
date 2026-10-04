#include "bits/stdc++.h"
using namespace std;
int friendpairs(int n){
    if(n==1 || n==2){
        return n;
    }
    return friendpairs(n-1)+(n-1)*friendpairs(n-2);
}
int main(){
    cout<<"No of pairs:"<<friendpairs(6)<<endl;
    int arr[4]={4,2,1,8};
    sort(arr,arr+3);
    for(int i=0;i<=3;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}