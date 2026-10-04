#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;
void stockspan(vector<int>&stock,vector<int>span){
    stack<int>s;
    s.push(0);
    span[0]=1;
    for(int i=1;i<stock.size();i++){
        int currprice=stock[i];
        while(!s.empty() && currprice>=stock[s.top()]){
            s.pop();

        }
        if(s.empty()){
            span[i]=i+1;
        }else{
            int prehight=s.top();
            span[i]=i-prehight;
        }

    }
    for(int i=0;i<span.size();i++){
        cout<<span[i]<<" ";
    }
}
int main(){
    // vector<int>stock={100,80,60,70,60,85,100};
    // vector<int>span={0,0,0,0,0,0,0};
    vector<int>stock={10,8,9,6,11};
    vector<int>span={0,0,0,0,0};
    stockspan(stock,span);
    return 0;
}