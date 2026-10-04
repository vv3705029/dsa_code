#include<iostream>
using namespace std;
int main(){
    //factorial of a number enterd by user
    /*int n;
    cout<<"Enter a number:";
    cin>>n;
    int factorial=1;
    for(int i=0;i<n;i++){
        factorial=factorial*(i+1);
    }
    cout<<"factorial of n:"<<factorial;*/

    //print the multiplication table of a number
    /*int n;
    int table=1;
    cout<<"Enter a number:";
    cin>>n;
    for(int i=1;i<=10;i++){
        table=n*i;
        cout<<n<<"*"<<i<<"="<<table;
        cout<<endl;
    }*/

    //Armstrong number
    /*int n=371;
    int num=n;
    int cubesum=0;
    while(num>0){
        int lastdig=num%10;
        cubesum+=lastdig*lastdig*lastdig;
        num/=10;
        
    }
    if(n==cubesum){
        cout<<"Armstrong number";

    }else{
        cout<<"Not a Armstrong number";

    }*/

    //for a positive number print all prime number from 2 to N
    int n;
    cout<<"Enter a number:";
    cin>>n;
    for(int i=2;i<=n;i++){
        int sum=0;
        int a=i;
        for(int j=1;j<=a;j++){
            if(a%j==0){
                sum+=1;
            }
        }
        if(sum==2){
            cout<<a<<",";
        }
    }
    return 0;
}