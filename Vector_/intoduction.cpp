#include<iostream>
#include<string>
using namespace std;
void funcarr(){
    int size;
    cout<<"Enter size of arr: ";
    cin>>size;
    int *arr=new int[size];//new is important 
    int x=1;
    for(int i=0;i<size;i++){
        arr[i]=x;
        cout<<arr[i]<<" ";
        x++;
    }
    cout<<endl;
    cout<<*(arr+2);
    
    delete[] arr;
}
int main(){
    funcarr();
    return 0;
}
//s
