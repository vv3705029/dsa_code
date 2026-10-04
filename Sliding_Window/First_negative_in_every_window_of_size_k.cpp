//  Using Nested Loops - O(n*k) time and O(1) space
// Sliding Window with Deque technique - O(n) time and O(k) space






//  Using Nested Loops - O(n*k) time and O(1) space


// #include <iostream>
// #include <vector>
// using namespace std;

// vector<int> firstNegInt(vector<int>& arr, int k) {
//     vector<int> res;
//     int n = arr.size();
    
//     // Loop for each subarray(window) of size k
//     for (int i = 0; i <= (n - k); i++) {
//         bool found = false;
        
//         // traverse through the current window
//         for (int j = 0; j < k; j++) {
            
//             // if a negative integer is found, then 
//             // it is the first negative integer for 
//             // the current window. Set the flag and break
//             if (arr[i + j] < 0) {
//                 res.push_back(arr[i + j]);
//                 found = true;
//                 break;
//             }
//         }
        
//         // if the current window does not contain 
//         // a negative integer
//         if (!found) {
//             res.push_back(0);
//         }
//     }
//     return res;
// }

// int main() {
//     vector<int> arr = {12, -1, -7, 8, -15, 30, 16, 28};
    
//     int k = 3;
//     vector<int> res = firstNegInt(arr, k);
//     for (int i = 0; i < res.size(); i++) {
//         cout << res[i] << " ";
//     }
//     return 0;
// }








// Sliding Window with Deque technique - O(n) time and O(k) space
#include <iostream>
#include <deque>
#include <vector>
using namespace std;

// Function to find the first negative integer
// in every window of size k
vector<int> firstNegInt(vector<int>& arr, int k) {
    deque<int>dq;
    vector<int>res;
    int n = arr.size();

    // Process the first window of size k
    for (int i = 0; i < k; i++) {
        if(arr[i]<0){
            dq.push_back(i);
        }
    }

    // Process rest of the elements, i.e., 
    // from arr[k] to arr[n-1]
    for (int i = k; i < n; i++) {
        if(!dq.empty()){
            res.push_back(arr[dq.front()]);
        }else{
            res.push_back(0);
        }
        

        // Remove the elements which are out of 
        // this window
        while (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }

        // Add the current element if it is negative
        if(arr[i]<0){
            dq.push_back(i);
        }

    }

    // For the last window, process it separately
    if(!dq.empty()){
     res.push_back(arr[dq.front()]);
        }else{
            res.push_back(0);
        }

    return res;
}

int main() {
    vector<int> arr = {12, -1, -7, 8, -15, 30, 16, 28};
    int k = 3;

    vector<int> res = firstNegInt(arr, k);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }

    return 0;
}