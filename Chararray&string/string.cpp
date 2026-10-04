#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main(){
    string str="apna collage";
    //getline(cin,str); //getline if break getline(cin,str,%)
    //cout<<str<<endl;
    //cout<<str[0]<<endl;
    //str="hello";
    //cout<<str<<endl;

    cout<<str.length()<<endl;
    cout<<str.substr(1,2)<<endl;
    cout<<str.find("na",4)<<endl;
    return 0;
}