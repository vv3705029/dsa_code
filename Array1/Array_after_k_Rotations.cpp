// [Naive Approach] Using Recursion - O(n × k) Time and O(k) Space
// [Better Approach] Using Extra Space - O(n) Time and O(n) Space
// [Expected Approach] Using Reversal Technique - O(n) Time and O(1)


// [Better Approach] Using Extra Space - O(n) Time and O(n) Space

// #include <iostream>
// #include <vector>
// using namespace std;
                    
// void rotateclockwise(vector<int>& arr, int k) {

//     int n = arr.size();

//     // Handle cases where k > n
//     k = k % n;

//     // Temporary vector to store rotated elements
//     vector<int> res;

//     for (int i = 0; i < n; i++) {
//         if(i<k){
//             res.push_back(arr[n+i-k]);
//         }else{
//             res.push_back(arr[i-k]);
//         }
//     }

//     // Copy rotated result back to original array
//     for(int i=0;i<n;i++){ 
//         arr[i]=res[i];
//     }
// }

// int main() {
    
//     vector<int> arr = {1, 2, 3, 4, 5, 6};
//     int k = 2;
    
//     rotateclockwise(arr, k);
//     for (auto it : arr) {
//         cout << it << " ";
//     }
//     return 0;
// }



// [Expected Approach] Using Reversal Algorithm - O(n) Time and O(1)
#include<iostream>
#include<vector>
using namespace std;

void rotateclockwise(vector<int>& arr, int k){
    int n = arr.size();
    if (n == 0) return;

    k = k % n;
    int i, j;

    // reverse last k elements
    for(int i=n-k,j=n-1;i<j;i++,j--){
        swap(arr[i],arr[j]);
    }

    // reverse first n - k e  lements  
    for(int i=0,j=n-k-1;i<j ;i++,j--){
        swap(arr[i],arr[j]);
    }
   
    // reverse the entire array
    for(int i=0,j=n-1;i<j;i++,j--){
        swap(arr[i],arr[j]);
    } 
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    int k = 7;

    rotateclockwise(arr, k); 
    for (int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }

    return 0;
}