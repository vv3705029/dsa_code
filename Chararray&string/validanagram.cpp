#include<iostream>
#include<string>
using namespace  std;
bool isanagram(string str1,string str2){
    if(str1.length()!=str2.length()){
        return false;
    }
    int count[26]={0};
    for(int i=0;i<str1.length();i++){
        int idx=str1[i]-'a';
        count[i]++;
    }
    for(int i=0;i<str2.length();i++){
        int idx=str2[i]-'a';
        if(count[i]==0){
            return false;           
        }
        count[i]--;
    }
    return true;

}
int main(){
    string str1="vikas",str2="askiv";
    cout<<isanagram(str1,str2);
    //method 1
    /*for(int i=0;i<str1.length()-1;i++){
        for(int j=0;j<(str1.length()-i-1);j++){
              if(str1[j]>str1[j+1]){
                swap(str1[j],str1[j+1]);
              }
              if(str2[j]>str2[j+1]){
                swap(str2[j],str2[j+1]);
              }
        }
    }
    if(str1==str2){
        cout<<"Valid anagram";
    }else{
        cout<<"not Valid anagram";
    }*/

    //
    
    return 0;
}