#include<iostream>
using namespace std;
int search(int arr[4][4],int n,int key){
     for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
           if(arr[i][j]==key){
               return 1;
           }
        }
    }
    return 0;
}
int main(){
    int arr[4][4]={{10,20,30,40},{15,25,35,45},{27,29,37,48},{32,33,39,50}};
    int n=4,m=4;
    int key;
    cout<<"Enter a number: ";
    cin>>key;
    cout<<search(arr,n,key);
    return 0;
}