// A Set is a container which stores unique elements in some sorted order.
// It is an implementation of a Self-Balancing Binary Search Tree, specifically 
// a Red-Black Tree which ensures,Search, insert, and delete in O(log n) time.
// Does not allow duplicates.Elements are always sorted in ascending order by default.
// You can also choose your own way of ordering them using a custom rule (comparator).
// Compared to unordered_set, the time taken to search, insert, and delete an higher, 
// but we get elements in sorted order and also support additional functions like upper_bound() and lower_bound().



#include <iostream>
#include <set>
using namespace std;

int main() {

    // Creating an empty set
    set<int> s1;

    // Initialize set with list 
    set<int> s2 = {1, 2, 3, 2, 1}; 

    // Traversing the set
    for (auto& x : s2)
        cout << x << " ";
    cout << endl;

    return 0;
}