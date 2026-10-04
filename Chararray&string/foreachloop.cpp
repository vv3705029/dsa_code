#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main(){
    string str="apna collage";
    for(int i=0;i<str.length();i++){//dot operator
        cout<<str[i]<<" ";
    }
    cout<<endl;
    for(char ch:str){
        cout<<ch<<" ";
    }
    return 0;
}