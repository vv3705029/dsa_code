#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
    string str="hello world";

    //Traversing using index
    for(int i=0;i<str.size();i++){
        cout<<str[i]<<" ";
    }
    cout<<endl;
    //Traversing using range-based for loop
    for(auto ch:str){
        cout<<ch<<" ";
    }

    cout<<endl;
    //traversing using iterater
    for(auto it=str.begin();it !=str.end();it++){
        cout<<*it<<" ";
    }

    //Join()
    // vector<string>words={"c++","vikas","verma"};
    // string temp=words.join(words," ");

    //trim
    // string s="vikas verma    v ";
    // string x=trim(s);

    return 0;
}