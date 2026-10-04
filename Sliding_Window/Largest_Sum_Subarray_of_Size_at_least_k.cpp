// [Naive Approach] Checking All Possible Subarrays - O(n^2) Time and O(1) Space
// [Better Approach] Kadane's Algorithm with Sliding Window - O(n) Time and O(n) Space
// [Expected Approach] Sliding Window with Kadane's Optimization - O(n) Time and O(1) Space



// Given an array arr[] and an integer k, find the maximum sum among all contiguous 
// subarrays having a length greater than or equal to k.

// #include <iostream>
// #include <vector>
// #include <climits>
// using namespace std;

// int maxSumWithK(vector<int> &arr, int k) {
//     int n = arr.size(), res = INT_MIN;

//     // Iterate over all possible starting points
//     for (int i = 0; i < n; i++) {
        
//         int sum = 0;
        
//         for (int j = i; j < n; j++) {
//             sum += arr[j];
            
//             // If size of current subarray is k
//             // or more
//             if (j - i + 1 >= k) res = max(res, sum);
//         }
//     }
//     return res;
// }

// int main() {
//     vector<int> arr = {1, 1, 1, 1, 1, 1};
//     int k = 2;
//     cout << maxSumWithK(arr, k) << endl;
//     return 0;
// }



// [Expected Approach] Sliding Window with Kadane's Optimization - O(n) Time and O(1) Space

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxSumWithK(vector<int> &arr, int k)
{
    // Calculate initial sum of
    // first k elements (first window)
    int sum = 0;
    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
    }

    int last = 0;
    int j = 0;
    int maxSum = INT_MIN;
    maxSum = max(maxSum, sum);

    // Process rest of the array after first k elements
    for (int i = k; i < arr.size(); i++)
    {
        // Add current element to window sum
        sum+=arr[i];

        // Add element at j to the accumulated prefix
        last=last+arr[j++];

        // Update maxSum if current window sum is greater
        maxSum=max(sum,maxSum);

        // Remove the accumulated negative prefix
        // if it increases the overall subarray sum
        if(last<0){
            sum=sum-last;
            maxSum=max(maxSum,sum);
            last=0;
        }
        
    }

    return maxSum;
}

int main()
{
    vector<int> arr = {1,-2,2,-3};
    int k = 3;

    cout << maxSumWithK(arr, k);

    return 0;
}