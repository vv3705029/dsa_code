// [Naive Approach] Using Sorting - O(n*m*log n)Time O(m)Space
// [Expected Approach 1] Character by Character Matching - O(n * m) Time and O(m) Space
// [Expected Approach 2] Using Divide and Conquer Algorithm - O(n*m) Time O(m) Space
// [Expected Approach 3] Using Trie - O(n*m) Time O(n*m) Space




// Input: arr[] = [“geeksforgeeks”, “geeks”, “geek”, “geezer”]
// Output: “gee”
// Explanation: “gee” is the longest common prefix in all the given strings: “geeksforgeeks”, “geeks”, “geeks” and “geezer”.



// [Naive Approach] Using Sorting - O(n*m*log n)Time O(m)Space

// The idea is to sort the array of strings and find the common prefix of the
//  first and last string of the sorted array.

// C++ program to find the longest common prefix
// using Sorting
// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// // Function to find the longest common prefix
// string longestCommonPrefix(vector<string>& arr) {

//     // Sort the vector of strings
//     sort(arr.begin(), arr.end());

//     // Compare the first and last strings
//     // in the sorted list
//     string first = arr.front();
//     string last = arr.back();
//     int minLength = min(first.size(), last.size());

//     int i = 0;
  
//     // Find the common prefix between the first
//     // and last strings
//     while (i < minLength && first[i] == last[i]) {
//         i++;
//     }

//     // Return the common prefix
//     return first.substr(0, i);
// }

// int main() {
//     vector<string> arr = {"geeksforgeeks", "geeks",
//                            "geek", "geezer"};
//     cout << longestCommonPrefix(arr) << endl;

//     return 0;
// }





//[Expected Approach 1] Character by Character Matching - O(n * m) Time and O(m) Space
// using Character by Character Matching

#include <iostream>
#include <vector>
using namespace std;

// Function to find the longest common prefix
// from the set of strings
// string longestCommonPrefix(vector<string>& arr) {
  
//   	// Find length of smallest string
//     int minLen = arr[0].length();

//     for(string &str: arr)
//         minLen = min(minLen, (int)str.size());

//     string res;
//     for (int i = 0; i < minLen; i++) {
      
//         // Current character (must be the same
//         // in all strings to be a part of result)
//         char ch = arr[0][i];

//         for (string &str: arr) {
//             if (str[i] != ch)    
//                 return res;
//         }

//         // Append to result
//         res.push_back(ch);
//     }
  	
//     return res;
// }

// int main() {
//     vector<string> arr = {"geeksforgeeks", "geeks", 
//                           			"geek", "geezer"};
//     cout << longestCommonPrefix(arr);
//     return 0;
// }


