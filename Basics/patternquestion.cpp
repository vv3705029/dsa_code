#include<iostream>
using namespace std;
int main(){
    /*int n=5;
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            cout<<i;
        }
        cout<<endl;
    }*/

    //question no 2
    /*int n=5;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=(n-i);j++){
            cout<<" "<<" ";
        }
        for(int j=1;j<=n;j++){
            cout<<"*"<<" ";
        }
        cout<<endl;
    }*/

    //Question no 3
    int n=5;
    int  a=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=(n-i);j++){
            cout<<" "<<" ";
        }
        for(int j=i;j>=1;j--){
            
            cout<<j<<" ";
             
        }
        for(int j=2;j<=i;j++){
            cout<<j<<" ";
        }
        a++;
        cout<<endl;
        
    }

    return 0;
}