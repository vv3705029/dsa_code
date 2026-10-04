#include<iostream>
using namespace std;
/*void func(int arr[]){
    arr[0]=1000;
}*/

//or this is also same
void func2(int *arr){
    arr[0]=1000;
}
int main(){
    /*int a=5;
    int *ptr=&a;
    cout<<ptr<<endl;*/

    int arr[]={1,7,5,4,8,4,2};
    int len=sizeof(arr)/sizeof(int);
    //cout<<*arr<<endl;//arr[0]
    //cout<<*(arr+1)<<endl;//arr[1]
    //cout<<arr<<endl;//pointer of array
    func2(arr);//passing arr name is eq to passing the pointer
    cout<<arr[0]<<endl;
    return 0;
}