#include<iostream>
using namespace std;
int main(){
    int arr[]={5,4,17,7,3,47};
    int max=arr[0];
    int len=sizeof(arr)/sizeof(int);
    for(int i=0;i<len;i++){
        if(max<arr[i]){
            max=arr[i];
        }
    }
    cout<<"Larges in te arr: "<<max;
    return 0;
}
