#include<iostream>
using namespace std;

int prime(int a){
    int x=0;
    for(int i=1;i<=a;i++){
        if(a%i==0){
             x++;
        }
       
    }
    return x;
}
int main(){
    int a;
    int b=prime(1);
    if(b==2){
        cout<<"a is a prime number.";
    }else{
         cout<<"a is not a prime number.";
    }
    return 0;
}