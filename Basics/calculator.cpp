#include<iostream>
using namespace std;
int main(){
    // int a,b,value;
    // cout<<"Enter number a:";
    // cin>>a;
    // cout<<"Enter number b:";
    // cin>>b;
    // char op;
    // cout<<"Enter sign:";
    // cin>>op;
    // switch (op)
    // {
    // case '+':
    //     cout<<"a+b="<<a+b;
    //     break;
    // case '-':
    //     cout<<"a-b="<<a-b;
    //     break;
    // case '/':
    //     cout<<"a/b="<<a/b;
    //     break;
    // case '*':
    //     cout<<"a*b="<<a*b;
    //     break;
    
    // default:
    //     break;
    // }
    char ch='B';
    cout<<char('a'+ch-'A')<<endl;
    int temp=int(ch-'A');
    cout<<char(temp+'a')<<endl;
    return 0;
}