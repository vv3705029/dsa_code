#include <iostream>
#include <vector>
using namespace std;

class SegmentTree {
    vector<int> tree; // Segment tree array
    int n;            // Size of the input array

public:
    SegmentTree(vector<int>& arr) {
        this->n = arr.size();
        tree.resize(4 * n);
        buildTree(arr, 0, n - 1, 0);
    }

    // Build the segment tree
    void buildTree(vector<int>& arr, int start, int end, int node) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }
        int mid = start + (end - start) / 2;

        buildTree(arr, start, mid, 2 * node + 1);   // Left child
        buildTree(arr, mid + 1, end, 2 * node + 2); // Right child

        tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
    }

    // Print the segment tree
    void printTree() {
        cout << "Segment Tree: ";
        for (int i = 0; i < tree.size(); i++) {
            cout << tree[i] << " ";
        }
        cout << endl;
    }

    // Update query helper function
    void updateQuery(int idx, int val, int start, int end, int node) {
        if (start == end) { // Leaf node
            tree[node] = val;
            return;
        }

        int mid = start + (end - start) / 2;
        if (idx >= start && idx <= mid) { // Update in left child
            updateQuery(idx, val, start, mid, 2 * node + 1);
        } else { // Update in right child
            updateQuery(idx, val, mid + 1, end, 2 * node + 2);
        }

        // Update the current node after updating the child
        tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
    }

    // Public method for updating values
    void updateQuery(int idx, int val) {
        if (idx < 0 || idx >= n) {
            cerr << "Invalid index for update!" << endl;
            return;
        }
        updateQuery(idx, val, 0, n - 1, 0);
    }
};

int main() {
    // Example usage of Segment Tree
    vector<int> arr = {6, 8, -1, 2, 17, 1, 3, 2, 4};
    SegmentTree t1(arr);

    t1.printTree();

    // cout << "Updating index 4 to value 6..." << endl;
    // // t1.updateQuery(4, 6);

    // t1.printTree();

    return 0;
}
