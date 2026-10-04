#include<iostream>
#include<vector>
using namespace std;
void subseq(string s,int index,string path,vector<string>&ans){
    if(index==s.size()){
        ans.push_back(path);
        return;
    }
    subseq(s,index+1,path,ans);
    subseq(s,index+1,path+s[index],ans);
}
int main(){
    string s="abc";
    vector<string>ans;
    subseq(s,0,"",ans);
    for(auto x:ans){
        cout<<x<<" ";
    }

}
