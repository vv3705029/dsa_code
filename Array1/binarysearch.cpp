#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
int binary(int *arr,int n,int key){
    int st=0;
    int en=n-1;
    
    while (st<=en){
        int mid=(st+en)/2;
        if(arr[mid]==key){
            return mid;
        }else{
            if(arr[mid]<key){
                st=mid+1;
            }else{
                en=mid-1;
            }
        }
        
    }
    return 0;
    
}
int main(){
    int arr[]={2,3,4,7,12};
    int n=sizeof(arr)/sizeof(int);
    int key;
    cout<<"Enter a number: ";
    cin>>key;
    cout<<binary(arr,n,key)<<endl;

    int temp=INT_MIN;
    cout<<temp<<endl;
    bool x=temp>1?true:false;
    cout<<x<<endl;
    return 0;
}