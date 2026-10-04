#include<iostream>
using namespace std;
int main(){
    //creating an array
    //int mark[50];
    //int mark[]={1,2,3};
    //cout<<mark[1]<<endl;
    //cout<<sizeof(mark)/sizeof(int);

    /*int mark[]={34,5,4,3,2,5,56,6};
    int len=sizeof(mark)/sizeof(int);
    for(int i=0;i<len;i++){
        cout<<mark[i]<<endl;
    }*/

    //take input
    int n;
    cout<<"Enter length of array:";
    cin>>n;
    int mark[n];
    int len=sizeof(mark)/sizeof(int);
    for(int i=0;i<len;i++){
        cout<<"Enter a number: ";
        cin>>mark[i];
    }
    for(int i=0;i<len;i++){
        cout<<mark[i]<<" ";
    }
   return 0;
}