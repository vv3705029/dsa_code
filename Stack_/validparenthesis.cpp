#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;
bool validparenthesis(string str){
    stack<char>s;
    for(int i=0;i<str.length();i++){
        char ch=str[i];
        if(ch=='(' ||ch=='{' || ch=='['){
            s.push(ch);
        }else{//closing
            if(s.empty()){
                return false;
            }
            //match
            char top=s.top();
            if((top=='(' && ch==')') || (top=='[' && ch==']') ||(top=='{' && ch=='}') ){
                s.pop();
            }else{
                return false;
            }
        }
    }
    return true;
}
int main(){
    string str1="([{}])";
    string str2="([{])";
    string str3="{])";
    cout<<validparenthesis(str1)<<endl;
    cout<<validparenthesis(str2)<<endl;
    cout<<validparenthesis(str3)<<endl;
    return 0;
}