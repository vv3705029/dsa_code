#include<iostream>
#include<string.h>
using namespace  std;
int main(){
    /*char word[50];
    cin>>word; //ignore whitespace
    cout<<"Your word is :"<<word;*/
    
    char sent[50];
    cin.getline(sent,50);
    cout<<"Your word is: "<<sent;
    return 0;
}