#include<iostream>
using namespace std;
int num(int a){
    if(a%2==0){
        cout<<"Even number.";
    }
    else{
        cout<<"Odd number.";
    }
}
int main(){
    num(5);
    return 0;
}