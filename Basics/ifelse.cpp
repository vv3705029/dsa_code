#include<iostream>
using namespace std;
int main(){
    /*int age;
    cout<<"Enter your age :";
    cin>>age;
    if(age>=18){
        cout<<"can vote";
    }else{
        cout<<"can't vote";
    }*/
    
    
    
    //largest of 2 number
    /*int a;
    int b;
    cout<<"Enter a number:";
    cin>>a;
    cout<<"Enter b number:";
    cin>>b;
    if(a>b){
        cout<<"a is larger:"<<a;
    }else{
        cout<<"b is larger:"<<b;
    }*/


    //even or odd
    /*int a;
    cout<<"Enter a number:";
    cin>>a;
    if(a%2==0){
        cout<<"Even";
    }else{
        cout<<"odd";
    }*/
    
    /*int mark=98;
    if(mark>=90){
        cout<<"A"<<endl;
    }else if (mark>=70){
        cout<<"B"<<endl;

    }else{
        cout<<"C";
    }*/

    //income tax calculater
    /*int income;
    int tax;
    cout<<"Enter yor income(in lakhs):";
    cin>>income;
    if(income<5)
    {
        tax=0;
    }else if (5<=income<=10)
    {
       tax=income*(100000)*(0.2);

    }else{
        tax=income*(100000)*(.3);
    }
    cout<<"Income tax:"<<tax;*/

    //largest of 3 number
    int a,b,c;
    cout<<"Enter a:";
    cin>>a;
    cout<<"Enter b:";
    cin>>b;
    cout<<"Enter c:";
    cin>>c;
    if(a>b && a>c){
        cout<<"Largest number:"<<a;
    }
    else if (b>a && b>c)
    {
        cout<<"Largest number:"<<b;
    }else{
        cout<<"Largest number:"<<c;
    }  
    return 0;
}