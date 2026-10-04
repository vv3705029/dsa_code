#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    
    string str = "Hella";

    //Reversing a string 

    reverse(str.begin(),str.end());
    cout<<str<<endl;

    //Sorting a string

    sort(str.begin(),str.end());
    cout<<str<<endl;
    return 0;
}