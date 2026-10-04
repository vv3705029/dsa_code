#include<iostream>
using namespace std;
int main(){
    int student[3][4];
    int n=3,m=4;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<"Enter a number: ";
            cin>>student[i][j];
        }
    }
    for(int i=0;i<n;i++){
         for(int j=0;j<m;j++){
            cout<<student[i][j]<<" ";
         }
         cout<<endl;
    }
}