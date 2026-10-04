#include<iostream>
using namespace std;
int main(){
    int a=10;
    int *ptr=&a;
    cout<<*ptr<<endl;

    int b=30;
    ptr=&b;
    cout<<*ptr;
    return 0;
}