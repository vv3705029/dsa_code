#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter a binary number: ";
    cin>>n;
    int sum=0;
    int power=1;
    while(n>0){
        int d=n%10;
        sum=sum+d*power;
        power*=2;
        n/=10;
    }
    cout<<"Decimal number: "<<sum;
    return 0;
}
