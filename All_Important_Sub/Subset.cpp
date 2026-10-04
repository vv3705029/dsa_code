#include <iostream>
#include <vector>
using namespace std;

void generateSubsets(vector<int>& nums, int index, vector<int>& path, vector<vector<int>>& result) {
    if (index == nums.size()) {
        result.push_back(path);
        return;
    }
    generateSubsets(nums, index + 1, path, result);
    path.push_back(nums[index]);
    generateSubsets(nums, index + 1, path, result);
    path.pop_back();
}

int main() {
    vector<int> nums = {1, 2};
    vector<vector<int>> result;
    vector<int> path;
    generateSubsets(nums, 0, path, result);
    for (auto subset : result) {
        for (int num : subset)
            cout << num << " ";
        cout << endl;
    }
    return 0;
}
