#include<iostream>
using namespace std;
int  linear(int *arr1,int len,int x){
      for(int i=0;i<len;i++){
        if(x==arr1[i]){
           return i; 
        }
    }
    return -1;
}
int main(){
    int arr1[]={77,9,4,5,6,1,5,2};
    int len=sizeof(arr1)/sizeof(int);
    int x;
    cout<<"Enter a number:";
    cin>>x;
    cout<<"Index of the number: "<<linear(arr1,len,x);
    return 0;
}