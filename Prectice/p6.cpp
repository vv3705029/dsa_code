#include<iostream>
#include<stack>
using namespace std;
//  bool compare(char s,char t){
//         if(s==t){
//             return true;
//         }
//         return false;
//     }
//     bool isSubsequence(string s, string t) {
//         int n=s.size()-1;
//         int m=t.size()-1;
//         while(n>=0 || m>=0){
//             char s1=s[n];
//             char t1=t[m];
//             if(compare(s1,t1)){
//                 n--;
//                 m--;
//             }
//             m--;
//         }
//         if(m==0 && n==0){
//             return true;
//         }
//         return false;
//     }
int main(){
    string s="abc";
    string t="aebdc";
    stack<char>st;
    st.push('a');
    st.push('  ');
    st.push('b');
    while(!st.empty()){
        cout<<st.top();
        st.pop();
    }
        
    return 0;
}