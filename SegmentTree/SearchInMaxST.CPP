#include <iostream>
#include <vector>
#include <climits> // For INT_MIN
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

    // Maximum query helper function
    int maxQuery(int qi, int qj, int si, int sj, int node) {
        if (qi > sj || qj < si) { // No overlap
            return INT_MIN;
        }
        if (si >= qi && sj <= qj) { // Complete overlap
            return tree[node];
        }
        // Partial overlap
        int mid = si + (sj - si) / 2;

        return max(maxQuery(qi, qj, si, mid, 2 * node + 1),
                   maxQuery(qi, qj, mid + 1, sj, 2 * node + 2));
    }

    // Public method for range queries
    int rangeQuery(int qi, int qj) {
        if (qi > qj || qi < 0 || qj >= n) {
            cerr << "Invalid query range!" << endl;
            return INT_MIN;
        }
        return maxQuery(qi, qj, 0, n - 1, 0); // qi, qj, si, sj, node
    }
};

int main() {
    // Range Maximum Queries
    vector<int> arr = {6, 8, -1, 2, 17, 1, 3, 2, 4};
    SegmentTree t1(arr);

    t1.printTree();

    cout << "Maximum value in range [0, 2]: " << t1.rangeQuery(0, 2) << endl;
    cout << "Maximum value in range [3, 7]: " << t1.rangeQuery(3, 7) << endl;

    return 0;
}
