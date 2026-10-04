#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& arr, int target){
    int left = 0, right = arr.size() - 1;

    while (left < right) {
        int current_sum = arr[left] + arr[right];
        // If current sum = target, return left and right
        if (current_sum == target) {
            return { left + 1, right + 1 };
        }
        // If current sum < target, then increase the
        // current sum by moving the left pointer by 1
        else if (current_sum < target) {
            left++;
        }
        else {
            // If current sum > target, then decrease the
            // current sum by moving the right pointer by 1
            right--;
        }
    }

    // no pair sum with given target
    return { -1, -1 };
}

int main(){
    //array is sorted n assending order
    vector<int> arr = { 2, 7, 11, 15 };
    int target = 9;
    vector<int> result = twoSum(arr, target);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}