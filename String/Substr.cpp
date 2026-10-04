#include <iostream>
#include <string>
using namespace std;

int main() {
    //The .substr(pos,len) is used to extract a part of a string, where pos means the starting 
    //position and len means how many characters you want to copy.
    //Time complexity of extraction is O(len).
    string str = "Hello Geeks";

    // Extract "Hello"
    string sub1 = str.substr(0, 5);   
    cout << "Substring 1: " << sub1 << endl;

    // Extract "Geeks"
    string sub2 = str.substr(6, 5);  
    cout << "Substring 2: " << sub2 << endl;

    return 0;
}