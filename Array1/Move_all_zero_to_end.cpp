// [Naive Approach] Using Temporary Array - O(n) Time and O(n) Space
// [Better Approach] Two Traversals-O(n) Time and O(1) space
// [Expected Approach] One Traversal-O(n) Time and O(1) space



// [Naive Approach] Using Temporary Array - O(n) Time and O(n) Space
// #include<iostream>
// #include<vector>
// using namespace std;
// void pushZerosToEnd(vector<int>&arr){
//     int n=arr.size();
//     vector<int>temp(n);
//     // to keep track of the index in temp[]
//     int j=0;

//     // Copy non-zero elements to temp[]
//     for(int i=0;i<n;i++){
//         if(arr[i]!=0){
//             temp[j++]=arr[i];
//         }
//     }
//     // Fill remaining positions in temp[] with zeros
//     while (j<n)
//     {
//         temp[j++]=0;
//     }

//     // Copy all the elements from temp[] to arr[]
//     for(int i=0;i<n;i++){
//         arr[i]=temp[i];
//     }
    
// }
// int main()
// {
//     vector<int> arr = {1, 2, 0, 4, 3, 0, 5, 0};
//     pushZerosToEnd(arr);
//     for (int num : arr)
//     {
//         cout << num << " ";
//     }
//     return 0;
// }




//[Better Approach] Two Traversals-O(n) Time and O(1) space
// #include <iostream>
// #include <vector>
// using namespace std;

// void pushZerosToEnd(vector<int> &arr)
// {

//     int count = 0;

//     // If the element is non-zero, replace the element at
//     // index 'count' with this element and increment count
//     for (int i = 0; i < arr.size(); i++)
//     {
//         if (arr[i] != 0)
//             arr[count++] = arr[i];
//     }

//     // Now all non-zero elements have been shifted to
//     // the front. Make all elements 0 from count to end.
//     while (count < arr.size())
//         arr[count++] = 0;
// }

// int main()
// {
//     vector<int> arr = {1, 2, 0, 4, 3, 0, 5, 0};
//     pushZerosToEnd(arr);
//     for (int num : arr)
//     {
//         cout << num << " ";
//     }
//     return 0;
// }




// [Expected Approach] One Traversal-O(n) Time and O(1) space
#include <iostream>
#include <vector>
using namespace std;

void pushZerosToEnd(vector<int>& arr) {
  
    // Pointer to track the position 
    // for next non-zero element
    int count = 0;
     
    for (int i = 0; i < arr.size(); i++) {

        // If the current element is non-zero
        if (arr[i] != 0) {
          
            // Swap the current element with 
            // the 0 at index 'count'
            swap(arr[i], arr[count]);
            // Move 'count' pointer to the 
            // next position
            count++;
        }
    }
}

int main() {
    vector<int> arr = {1, 2, 0, 4, 3, 0, 5, 0};
    pushZerosToEnd(arr);
    for (int num : arr) {
        cout << num << " ";
    }
    return 0;
}