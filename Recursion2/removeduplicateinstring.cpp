#include<iostream>
#include<string>
using namespace std;
void removeduplicates(string str,string ans,int i,int map[26]){
    if(i==str.size()){
        cout<<"ans:"<<ans;
    }
    char ch=str[i];
    int mapidx=(int)(ch-'a');//'a'->0
    if(map[mapidx]==true){
        removeduplicates(str,ans,i+1,map);
    }else{
        map[mapidx]=true;
        removeduplicates(str,ans+str[i],i+1,map);
    }
}

int main(){
    string str="dddddmcmcmmmm";
    string ans=" ";
    int map[26]={false};
    removeduplicates(str,ans,0,map);
    return 0;
}