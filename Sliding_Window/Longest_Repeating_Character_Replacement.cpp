// Given a string s of length n consisting only of uppercase English letters
// ('A'–'Z') and an integer k (0 ≤ k ≤ n), you can change at most k characters
// in the string. Find the length of the longest substring that can be made
//  of all same character after performing at most k changes.

// Input : k = 2, s = ABABA
// Output : 5
// We can get maximum length by replacing 2 B's with A's

// Input : k = 4, s = HHHHHH
// Output : 6
// We get maximum length 6 without any replacement


// [Naive Approach] Check All Substrings with Frequency Count - O(n^3) Time and O(1) Space
// [Better Approach] Window Sliding for Every Character - O(26 * n) Time O(1) Space
// [Expected Approach] Window Sliding with Hash Map - O(n) Time and O(1) Space





// [Naive Approach] Check All Substrings with Frequency Count - O(n^3) Time and O(1) Space


// Consider all substrings by choosing start l and end r.
// For each substring, find the most frequent character..
// If (substring length − max frequency) ≤ k, update the maximum length.

// #include <iostream>
// #include <unordered_map>
// using namespace std;

// int getMaxFreq(string &s, int l, int r) {
//     unordered_map<char, int> m;
//     int res = 1;

//     // Count the frequency of each character 
//     // in the substring
//     for (int i = l; i <= r; ++i)
//         m[s[i]]++;

//     // Find the maximum frequency of any character
//     for (auto &e : m)
//         res = max(res, e.second); 

//     return res;
// }

// // function to find the maximum length of substring
// // with at most k changes
// int longestSubstr(string& s, int k)
// {
//     int maxlen = 1;
//     int n = s.size();
    
//     // Try every possible starting point of the substring
//     for (int l = 0; l < n; ++l) {
//         for (int r = l; r < n; ++r) {
          
//             // Get the maximum frequency of any 
//             // character in the substring [l, r]
//             int f = getMaxFreq(s, l, r);
          
//             // If the number of changes required is <= k,
//             // update the maximum length
//             if (r - l + 1 - f <= k)
//                 maxlen = max(maxlen, r - l + 1);
//         }
//     }
    
//     return maxlen;
// }

// int main()
// {
//     int k = 2;
//     string s = "ABABA";
//     cout << longestSubstr(s, k) << endl;

//     k = 4;
//     string B = "HHHHHH";
//     cout << longestSubstr(B, k) << endl;

//     return 0;
// }




// [Expected Approach] Window Sliding with Hash Map - O(n) Time and O(1) Space

#include <iostream>
#include <unordered_map>
using namespace std;

int longestSubstr(string& s, int k) {
    int n = s.size();
    unordered_map<char, int> freq;    
    int maxFreq = 0;  
    int res = 0;
    
    // Left boundary of the window 
    int l=0;
    
    // Right boundary of the window
    for (int r = 0; r < n; ++r) {
      
        // Increase the frequency of the 
        // current character
        freq[s[r]]++;
        
        // Update maxFreq with the frequency of
        // the most frequent character in the
        // current window
        maxFreq=max(maxFreq,freq[s[r]]);
        
        // Shrink the window if more than k changes
        // required
        if(r-l+1-maxFreq > k){
            freq[s[l]]--;
            ++l;
        }

        // Update the maximum length of the substring
        res=max(res,r-l+1);
    }
    
    return res;
}

int main() {
    int k = 2;
    string s = "ABABA";
    cout << longestSubstr(s, k) << endl;

    k = 4;
    s = "HHHHHH";
    cout << longestSubstr(s, k) << endl;

    return 0;
}