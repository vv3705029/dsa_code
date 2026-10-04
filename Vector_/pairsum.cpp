// #include<iostream>
// #include<vector>
// using namespace std;
// vector<int> pairsum(vector<int>arr,int target){
//     int st=0,end=arr.size()-1;
//     int currsum=0;
//     vector<int>ans;
//     while(st<end){
//         currsum=arr[st]+arr[end];
//         if(currsum==target){
//             ans.push_back(st);
//             ans.push_back(end);
//             return ans;
//         }else if(currsum>target){
//             end--;
//         }else{
//             st++;
//         }
//     }
// }
// int main(){
//     //T.C=O(n)
//     vector<int>vec={2,9,8,15};
//     int target=9;
//     vector<int>ans=pairsum(vec,target);
//     cout<<ans[0]<<" "<<ans[1];
//     return 0;
// }




//pair sum using hashmap

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool twoSum(vector<int> &arr, int target){
  
    // Create an unordered_set to store the elements
    unordered_set<int> s;

    for (int i = 0; i < arr.size(); i++){

        // Calculate the complement that added to
        // arr[i], equals the target
        int complement = target - arr[i];

        // Check if the complement exists in the set
        if (s.find(complement) != s.end())
            return true;

        // Add the current element to the set
        s.insert(arr[i]);
    }
  
    // If no pair is found
    return false;
}

int main(){
    vector<int> arr = {0, -1, 2, -3, 1};
    int target = -2;

    if (twoSum(arr, target))
        cout << "true";
    else
        cout << "false";

    return 0;
}