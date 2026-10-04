#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
     //more than n/3 times
      int arr[11]={1,3,2,5,1,3,1,5,1,5,5};
    unordered_map<int,int>m;
    for(int i=0;i<11;i++){
        if(m.count(arr[i])){
             m[arr[i]]++;
        }else{
            m[arr[i]]=1;
        }
    }
    for(pair<int,int>temp:m){
        if(temp.second>=3){
            cout<<temp.first<<endl;
        }
    }
    return 0;
}
