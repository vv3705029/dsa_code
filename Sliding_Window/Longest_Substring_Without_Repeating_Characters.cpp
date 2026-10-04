// [Naive Approach] Substrings Starting From Every Index - O(n^2) Time and O(1) Space
// [Expected Approach 1] Using Sliding Window - O(n) Time and O(1) Space




// #include <iostream>
// #include<vector>
// using namespace std;

// int longestUniqueSubstr(string &s){
//     int n = s.size();
//     int res = 0;

//     for (int i = 0; i < n; i++){

//         // Initializing all characters as not visited
//         vector<bool>vis(26,false);

//         for (int j = i; j < n; j++){

//             // If current character is visited
//             // Break the loop
//             if (vis[s[j]-'a']==true){
//                 break;
//             }else
//             {   
//                 // Else update the result if this window is larger,
//                 // and mark current character as visited. 
//                 res=max(res,j-i+1);
//                 vis[s[j]-'a']=true;
//             }
//         }
//     }
//     return res;
// }

// int main(){
//     string s = "geeksforgeeks";
//     cout << longestUniqueSubstr(s);
//     return 0;
// }




// [Expected Approach 1] Using Sliding Window - O(n) Time and O(1) Space
#include <iostream>
#include <vector>
using namespace std;


int longestUniqueSubstr(string& s) {
    if(s.length()==0 || s.length()==1){
        return s.length();

    }
    
    int res=0;
    vector<bool>vis(26,false);
    // left and right pointer of sliding window
    int left=0;
    int right=0;
    while (right < s.length()) {

        // If character is repeated, move left pointer marking
      	// visited characters as false until the repeating 
      	// character is no longer part of the current window
        while (vis[s[right]-'a']==true) {
            vis[s[left]-'a']=false;
            left++;
               
       	}
        vis[s[right]-'a']=true;
        // The length of the current window (right - left + 1)
        // is calculated and answer is updated accordingly.
        res=max(res,(right-left+1));
        right++;
    }
    return res;
}

int main() {
    string s = "geeksforgeeks";
    cout << longestUniqueSubstr(s);
    return 0;
}