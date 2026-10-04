// [Naive Approach] Fixed-Size Window Brute Force - O(n × k) time and O(1) space
// [Better Approach - 1] Using Prefix Sum - O(n) Time and O(n) space
// [Better Approach - 2] Sliding Window using Queue - O(n) Time and O(k) Space
// [Expected Approach] Optimized Sliding Window - O(n) Time and O(1) Space



// Fixed-Size Window Brute Force - O(n × k) time and O(1) space

// #include <iostream>
// #include <vector>
// using namespace std;

// int maxSubarraySum(vector<int>& arr, int k) {
//     int n = arr.size();
//     int maxSum = 0;

//     // check all subarrays of size k
//     for (int i = 0; i <= n - k; i++) {
//         int currSum = 0;

//         // compute sum of current subarray
//         for (int j = 0; j < k; j++) {
//             currSum += arr[i + j];
//         }

//         // update maximum sum
//         maxSum = max(maxSum, currSum);
//     }

//     return maxSum;
// }

// int main() {
//     vector<int> arr = {2, 1, 5, 1, 3, 2};
//     int k = 3;
//     cout << maxSubarraySum(arr, k) << endl;
//     return 0;
// }



// [Better Approach - 1] Using Prefix Sum - O(n) Time and O(n) Space

// #include <iostream>
// #include <vector>
// using namespace std;

// int maxSubarraySum(vector<int>& arr, int k) {
//     int n = arr.size();
//     vector<int> prefix(n + 1, 0);

//     // build prefix sum array
//     for(int i=0;i<n;i++){
//         prefix[i+1]=prefix[i]+arr[i];
//     }

//     int maxSum = 0;

//     // compute sum of each subarray of size k
//     // using prefix array
//     for (int i = 0; i <= n - k; i++) {
//         int j=i+k-1;
//         int currsum=prefix[j+1]-prefix[i];

//         maxSum=max(currsum,maxSum);
//     }

//     return maxSum;
// }

// int main() {
//     vector<int> arr = {2, 1, 5, 1, 3, 2};
//     int k = 3;
//     cout << maxSubarraySum(arr, k) << endl;
//     return 0;
// }



// [Better Approach - 2] Sliding Window using Queue - O(n) Time and O(k) Space

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int maxSubarraySum(vector<int>& arr, int k) {
    int n = arr.size();
    queue<int> q;
    int sum = 0, maxSum = 0;

    for (int i = 0; i < n; i++) {
        sum+=arr[i];
        q.push(arr[i]);

        // maintain window of size k
        if(q.size()>k){
            sum-=q.front();
            q.pop();
        }
        // update maximum when window size becomes k
        if (q.size() == k) {
            maxSum = max(maxSum, sum);
        }
    }

    return maxSum;
}

int main() {
    vector<int> arr = {2, 1, 5, 1, 3, 2};
    int k = 3;
    cout << maxSubarraySum(arr, k) << endl;
    return 0;
}