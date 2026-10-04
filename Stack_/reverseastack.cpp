#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

void pushbottom(stack<int>& s, int val) {
    if (s.empty()) {
        s.push(val); // push as bottom
        return;
    }
    int temp = s.top();
    s.pop();
    pushbottom(s, val);
    s.push(temp);
}

void reverse(stack<int>& s) {
    if (s.empty()) {
        return;
    }
    int temp = s.top();
    s.pop();
    reverse(s);
    pushbottom(s, temp);
}

void print(stack<int> s) { // Use pass-by-value to avoid modifying original stack
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    stack<int> s1; // STL stack (use lowercase 's')
    s1.push(3);
    s1.push(2);
    s1.push(1);

    cout << "Original Stack: ";
    print(s1);

    reverse(s1);

    cout << "Reversed Stack: ";
    print(s1);

    return 0;
}
