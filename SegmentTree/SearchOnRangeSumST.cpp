#include <iostream>
#include <vector>
using namespace std;

class SegmentTree {
    vector<int> tree; // Segment tree array
    int n;            // Size of the input array

public:
    SegmentTree(vector<int>& arr) {
        n = arr.size();
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

        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    void printTree() {
        cout << "Segment Tree: ";
        for (int i = 0; i < tree.size(); i++) {
            cout << tree[i] << " ";
        }
        cout << endl;
    }

    // Range sum query (helper function)
    int rangeSum(int qi, int qj, int si, int sj, int node) {
        if (qj < si || qi > sj) { // No overlap
            return 0;
        }
        if (si >= qi && sj <= qj) { // Complete overlap
            return tree[node];
        }
        // Partial overlap
        int mid = si + (sj - si) / 2;

        return rangeSum(qi, qj, si, mid, 2 * node + 1) +
               rangeSum(qi, qj, mid + 1, sj, 2 * node + 2);
    }

    // Public method for range queries
    int rangeQuery(int qi, int qj) {
        if (qi > qj || qi < 0 || qj >= n) {
            cerr << "Invalid query range!" << endl;
            return -1;
        }
        return rangeSum(qi, qj, 0, n - 1, 0); // qi, qj, si, sj, node
    }
};

int main() {
    // Range Sum Queries
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    SegmentTree t1(arr);

    t1.printTree();

    cout << "Range Sum (2 to 5): " << t1.rangeQuery(0,1) << endl;

    return 0;
}
