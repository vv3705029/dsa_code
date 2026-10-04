#include<iostream>
#include<string>
using namespace std;
int main(){
    //The + operator creates a new string, while append() modifies the existing string in place.
    string str1 = "Hello";
    string str2 = " Geeks";

    // Using + operator
    string result1 = str1 + str2;
    cout << "Concatenation using + : " << result1 << endl;

    // Using append() function
    string result2 = str1;
    result2.append(str2);
    cout << "Concatenation using append(): " << result2 << endl;

}