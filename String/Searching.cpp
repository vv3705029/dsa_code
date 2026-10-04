#include <iostream>
#include <string>
using namespace std;

int main() {
    //The find() function is used to search for a substring inside a string. If found, 
    //it returns the index (position) where the substring starts; if not, it returns a special value (npos).
    string str = "Hello Geeks";

    int pos = str.find("s");  

    if (pos < str.size()) {
        cout << "\"Geeks\" found at index: " << pos << endl;
    }
    cout<<str.size();
    return 0;
}