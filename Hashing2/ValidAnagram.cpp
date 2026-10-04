#include<iostream>
#include<unordered_map>
using namespace std;
bool validanagrame(string s,string t){
       unordered_map<char,int>fre;
       if(s.size()!=t.size()){
        return false;
       }
    for(int i=0;i<s.length();i++){
        if(fre.count(s[i])){
             fre[s[i]]++;
        }else{
            fre[s[i]]=1;
        }
    }
    //2nd to look for t's chars in freq
    for(int i=0;i<t.length();i++){
        if(fre.count(t[i])){
             fre[t[i]]--;
             if(fre[t[i]]==0){
                fre.erase(t[i]);
             }
        }else{
            return false;
        }
    }
    return fre.size()==0;
}
int main(){
    string s="race";
    string t="car";
    cout<<validanagrame(s,t);
    return 0;
}
