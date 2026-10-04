#include<iostream>
using namespace std;
int main(){
    int a=65;
    int n=4;
    for(int i=1;i<=n;i++){
        for(int k=n;k>=i;k--){
            cout<<" ";
        }
        for(int j=1;j<=i;j++){
            cout<<char(a)<<" ";
            a++;
        }
        for(int k=n;k>=i;k--){
            cout<<" ";
        }
        for(int k=n;k>=i;k--){
            cout<<" ";
        }
        for(int j=1;j<=i;j++){
            cout<<char(a)<<" ";
            a++;
        }
        cout<<endl;
    }
    return 0;
}
