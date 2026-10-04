#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool check(vector<int>&freq){
    for(int i=0;i<26;i++){
        if(freq[i]!=0){
            return false;
        }
    }
    return true;
}
bool search(string txt,string pat){
    vector<int>freq(26,0);
    int n=txt.size();
    int m=pat.size();

    for(int i=0;i<m;i++){
        freq[txt[i]-'a']+=1;
        freq[pat[i]-'a']-=1;
    }
    if(check(freq)){
        return true;
    }
    for(int i=m;i<n;i++){
        freq[txt[i-m]-'a']-=1;
        // Add the ith character into the window
        freq[txt[i]-'a']+=1;
        if(check(freq)){
            return true;
        }
    }
    return false;
}
int main() {
    string txt = "geeks";
    string pat = "z";
    if (search(txt, pat))
        cout << "true";
    else
        cout << "false";
    return 0;
}