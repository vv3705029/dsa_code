#include<iostream>
using namespace std;
int main(){
    //Characters of a string can be added with .push_back(), removed with .pop_back(), or altered using .insert() and .erase().
    //Time complexity for push/pop is O(1) and O(n) for insert/erase.
    string str = "Hello Geeks";

    // Adding a character at the end
    str.push_back('!');
    cout << "After push_back: " << str << endl;

    // Removing the last character
    str.pop_back();
    cout << "After pop_back: " << str << endl;

    // Inserting a substring
    str.insert(5, "C++");
    cout << "After insert: " << str << endl;

    // Erasing part of the string
    str.erase(0, 4); 
    cout << "After erase: " << str << endl;
    return 0;
}