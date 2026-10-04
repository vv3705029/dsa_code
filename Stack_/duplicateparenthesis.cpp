#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;
bool duplicateparenthesis(string str){
    stack<char>s;
    for(int i=0;i<str.length();i++){
        char ch=str[i];
        if(ch!=')'){//non-closing
            s.push(ch);
        }else{//closing
           if(s.top()=='('){
              return true;
           }
            while(s.top()!='('){
                s.pop();
            }
            s.pop();
        }
    }
    return false;

}
int main(){
    string str1="((a+b))";//inbalid:true
    string str2="((a+b)+(c+d))";//false
    
    cout<<duplicateparenthesis(str1)<<endl;
    cout<<duplicateparenthesis(str2)<<endl;
    
    return 0;
}