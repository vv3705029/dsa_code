// [Naive] Substring Checking - O(n * m) time and O(1) space
// [Optimal] Sliding Window - O(n + m) time and O(1) space


// [Naive] Substring Checking - O(n * m) time and O(1) space
// #include <iostream>
// #include <vector>
// #include <string>

// using namespace std;

// // Function to check if two strings are anagrams
// bool areAnagram(string s1, string s2) {
//     vector<int> cnt(26, 0);

//     int n=s1.size();
//     int m=s2.size();

//     for(int i=0;i<n;i++){
//         cnt[s1[i]-'a']+=1;
//     }
//     for(int i=0;i<m;i++){
//         cnt[s2[i]-'a']-=1;
//     }
//     for(int i=0;i<26;i++){
//         if(cnt[i]!=0){
//             return false;
//         }
//     }
//     return true;

// }

// int search(string &pattern, string &text) {
//     int res=0;
//     int n=text.size();
//     int m=pattern.size();

//     for(int i=0;i<=n-m;i++){
//         if(areAnagram(text.substr(i,m),pattern)){
//             res++;
//         }
//     }
//     return res;
    
// }

// int main() {

//     string text = "forxxorfxdofr";
//     string pattern = "for";

//     cout << search(pattern, text);

//     return 0;
// }


//[Optimal] Sliding Window - O(n + m) time and O(1) space

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Two strings are anagram if the count
// of characters of each string cancel
// each other out.
bool isAnagram(vector<int> &cnt) {
    for (int i = 0; i < 26; i++) {
        if (cnt[i] != 0) return false;
    }
    return true;
}

int search(string &pattern, string &text) {

    int m = pattern.length();
    int n = text.length();

    // If pattern length is greater than text length
    if (m > n) return 0;

    vector<int> cnt(26, 0);

    // Count characters of pattern
    for (char ch : pattern) {
        cnt[ch - 'a']++;
    }

    // Process first window (size m-1)
    for (int i = 0; i < m - 1; i++) {
        cnt[text[i] - 'a']--;
    }

    int ans = 0;

    // Sliding window
    for (int i = m - 1; i < n; i++) {

        // Add new character
        cnt[text[i] - 'a']--;

        // Check anagram
        if (isAnagram(cnt)) ans++;

        // Remove first character of window
        cnt[text[i - m + 1] - 'a']++;
    }

    return ans;
}

int main() {
    string text = "forxxorfxdofr";
    string pattern = "for";

    cout << search(pattern, text);

    return 0;
}