// [Naive Approach] - Using Nested Loops - O(n * k) Time and O(1) Space
// [Better Approach] - Using Max-Heap - (n * log n) Time and O(n) Space
// [Expected Approach] - Using Deque - O(n) Time and O(k) Space



// Using Nested Loops - O(n * k) Time and O(1) Space

// #include <iostream>
// #include <vector>
// using namespace std;

// vector<int> maxOfSubarrays(vector<int>& arr, int k) {
//     int n = arr.size();

//     // to store the results
//     vector<int> res;
  
//     for (int i = 0; i <= n - k; i++) {
      
//         // Find maximum of subarray beginning
//         // with arr[i]
//         int max = arr[i];
//         for (int j = 1; j < k; j++) {
//             if (arr[i + j] > max)
//                 max = arr[i + j];
//         }
//         res.push_back(max);
//     }
  
//     return res;
// }

// int main() {
//     vector<int> arr = { 1, 2, 3, 1, 4, 5, 2, 3, 6 };
//     int k = 3;
//     vector<int> res = maxOfSubarrays(arr, k);
//     for (int maxVal : res) {
//         cout << maxVal << " ";
//     }
//     return 0;
// }



// Using Max-Heap - (n * log n) Time and O(n) Space

// #include <iostream>
// #include <vector>
// #include<queue>
// using namespace std;

// vector<int> maxOfSubarrays(const vector<int>& arr, int k) {
//     int n = arr.size();

//     // to store the results
//     vector<int> res;

//     // to store the max value
//     priority_queue<pair<int, int>> heap;

//     // Initialize the heap with the first k elements
//     for (int i = 0; i < k; i++)
//         heap.push({ arr[i], i });

//     // The maximum element in the first window
//     res.push_back(heap.top().first);

//     // Process the remaining elements
//     for (int i = k; i < arr.size(); i++) {

//         // Add the current element to the heap
//         heap.push({ arr[i], i });

//         // Remove elements that are outside the current
//         // window
//         while (heap.top().second <= i - k)
//             heap.pop();

//         // The maximum element in the current window
//         res.push_back(heap.top().first);
//     }

//     return res;
// }

// int main() {
//     vector<int> arr = { 1, 2, 3, 1, 4, 5, 2, 3, 6 };
//     int k = 3;
//     vector<int> res = maxOfSubarrays(arr, k);
//     for (int maxVal : res) {
//         cout << maxVal << " ";
//     }
//     return 0;
// }





//[Expected Approach] - Using Deque - O(n) Time and O(k) Space

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> maxOfSubarrays(vector<int>& arr, int k) {

    // to store the results
    vector<int> res;
  
    // create deque to store max values
    deque<int> dq(k);

    // Process first k (or first window) elements of array
    for (int i = 0; i < k; ++i) {
      
        // For every element, the previous smaller elements 
        // are useless so remove them from dq
        while (!dq.empty() && arr[i] >= arr[dq.back()]) {
          
            // Remove from rear
            dq.pop_back();
        }

        // Add new element at rear of queue
        dq.push_back(i);
    }

    // Process rest of the elements, i.e., from arr[k] to arr[n-1]
    for (int i = k; i < arr.size(); ++i) {
      
        // The element at the front of the queue is the largest 
        // element of previous window, so store it
        res.push_back(arr[dq.front()]);

        // Remove the elements which are out of this window
        while (!dq.empty() && dq.front() <= i - k) {
          
            // Remove from front of queue
            dq.pop_front();
        }

        // Remove all elements smaller than the currently being 
        // added element (remove useless elements)
        while (!dq.empty() && arr[i] >= arr[dq.back()]) {
            dq.pop_back();
        }

        // Add current element at the rear of dq
        dq.push_back(i);
    }

    // store the maximum element of last window
    res.push_back(arr[dq.front()]);

    return res;
}

int main() {
    vector<int> arr = {1, 2, 3, 1, 4, 5, 2, 3, 6};
    int k = 3;
    vector<int> res = maxOfSubarrays(arr, k);
    for (int maxVal : res) {
        cout << maxVal << " ";
    }
    return 0;
}