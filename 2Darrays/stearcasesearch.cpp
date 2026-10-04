#include <iostream>
using namespace std;
bool search(int arr[][4],int n,int m,int key){
    int i=0,j=m-1;
    while (i<n &&j>=0){
         int cell=arr[i][j];
         if(arr[i][j]==key){
            cout<<"Found at cell:("<<i<<","<<j<<")";
            return true;
         }else if (arr[i][j]>key){
            j--;   
         }else{
            i++;
         }
         
    }
    cout<<"key not found.";
    return false;
}
int main()
{
    int arr[4][4] = {{10, 20, 30, 40}, {15, 25, 35, 45}, {27, 29, 37, 48}, {32, 33, 39, 50}};
    int key;
    cout<<"Enter a key: ";
    cin>>key;
    search(arr,4,4,key);
    return 0;
}