#include<iostream>
using namespace std;
int main(){
    
    /*for(int i=0;i<5 ;i++){
       cout<<"apna collage"<<endl;
    }*/

    /*int n;
    cout<<"Enter a number:";
    cin>>n;
    for(int i=1;i<=n;i++){
        cout<<i<<endl;
    }*/


    //sum of n natural number
    /*int n;
    int sum=0;
    cout<<"Enter a number:";
    cin>>n;
    for(int i=1;i<=n;i++){
        sum+=i;
    }
    cout<<"Sum of n natural number:"<<sum;*/

    //while loop
    /*int count=0;
    while(count<10){
        cout<<count<<endl;
        count++;
    }*/

    //print the squarp loop using for loop
    /*int n=4;
    for(int i=0;i<n;i++){
        for (int j=0;j<=i;j++){
            cout<<"*";
        }
        cout<<endl;
    }*/

    //print number from n to 1
    /*int n=10;
    for(int i=n;i>0;i--){
        cout<<i<<endl;
    }*/

    //sumof digits of a number using while loop
    /*int n=10829;
    int sum=0;
   
    while(n>0){
        int d=n%10;
        if(d%2==0){
            sum+=d;
        }
        n=n/10;
    }
    cout<<sum;*/

    //print digits of a given number in reversr order using while loop
    /*int n=10829;
    while(n>0){
        int d=n%10;
        cout<<d<<' ';
        n=n/10;
    }*/

    //reverse the number and print the result
    int n=10829;
    int reverse=0;
    while(n>0){
        int d=n%10;
        reverse=reverse*10+d;
        n=n/10;
    }
    cout<<reverse;
    return 0;
}