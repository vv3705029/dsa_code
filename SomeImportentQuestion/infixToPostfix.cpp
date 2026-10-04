#include<iostream>
#include<string>
#include<stack>
using namespace std;

int prec(char c){
   if(c=='^'){
        return 3;
   } else if(c=='*' || c=='/'){
        return 2;
   }else if(c=='+' || c=='-'){
        return 1;
   }else{
        return -1;
   }
}
string infixToPostfix(string s){
    stack<char>st;
    string answer;
    for(int i=0;i<s.length();i++){
        char c=s[i];
        if((c>='a' && c<='z') ||(c>='A' && c<='Z') || (c>='0' && c<='9')){
           answer+=c;
        }else if(c=='('){
            st.push('(');
        }else if(c==')'){
            while (st.top()!='('){
                answer+=st.top();
                st.pop();
            }
            st.pop();
        }else{
            while (!st.empty() && prec(c)<=prec(st.top())){
                answer+=st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while(!st.empty()){
        answer+=st.top();
        st.pop();
    }
    return answer;
}
int main(){
    string s="(a+b)*(c+d)";
    cout<<infixToPostfix(s);
    return 0;
}