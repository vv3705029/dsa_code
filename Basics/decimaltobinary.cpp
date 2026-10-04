#include<iostream>
using namespace std;
int main(){
    int n;cout<<"Enter a decimal number: ";
    cin>>n;
    int sum=0;
    int power=1;
    while(n>0){
        int d=n%2;
        sum+=d*power;
        power=power*10;
        n=n/2;
    }
    cout<<"Binary number: "<<sum;
    
    return 0;
}