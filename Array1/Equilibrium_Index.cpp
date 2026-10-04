//[Expected Approach] Running Prefix Sum and Suffix Sum - O(n) Time and O(1) Space


// #include <iostream>
// #include <vector>
// using namespace std;

// int equilibriumPoint(vector<int>& arr) {
//     int prefSum = 0, total = 0;

//     // Calculate the array sum
//     for (int ele: arr) {
//         total += ele;
//     }

//     // Iterate pivot over all the elements
//     // of the array and till prefSum != suffSum
//     for(int i=0;i<arr.size();i++){
//         int sufSum=total-prefSum-arr[i];
//         if(prefSum==sufSum){
//             return i;
//         }
//         prefSum+=arr[i];
//     }

//     return -1;
// }

// int main() {
//     vector<int> arr = { 1,2,0,3 };

//     cout << equilibriumPoint(arr) << endl;
//     return 0;
// }



// [Naive Approach] Using Nested Loop - O(n^2) Time and O(1) Space
#include <iostream>
#include <vector>
using namespace std;

int findEquilibrium(vector<int>& arr) {
    int n=arr.size();
    // Check for indexes one by one until
    // an equilibrium index is found 
    for (int i = 0; i < arr.size(); ++i) {
      
      	//get left sum
        int leftsum=0;
        for(int j=0;j<i;j++){
            leftsum+=arr[j];
        }
        //get right sum
        int rightsum=0;
        for(int k=i+1;k<n;k++){
            rightsum+=arr[k];
        }
        if(leftsum==rightsum){
            return i;
        }
    }
    
    return -1;
}

int main() {
    vector<int> arr = {1,2,0,3,0,6};

    cout << findEquilibrium(arr);
    return 0;
}