#include<iostream>
#include<string>
using namespace std;
int LCSrec(string str1,string str2){
    
    if(str1.size()==0 || str2.size()==0){
        return 0;
    }
    int n=str1.size();
    int m=str2.size();

    if(str1[n-1]==str2[m-1]){
        return 1+LCSrec(str1.substr(0,n-1),str2.substr(0,m-1));
    }else{
        int ans1=LCSrec(str1.substr(0,n-1),str2);
        int ans2=LCSrec(str1,str2.substr(0,m-1));

        return max(ans1,ans2);
    }
}
int main(){
    // string str1="abcdge";
    // string str2="abedg";
    string str1="abcd";
    string str2="aceb";
    cout<<LCSrec(str1,str2);
    return 0;
}