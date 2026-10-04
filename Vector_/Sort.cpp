#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void print(vector<int>vec){
    for(auto it:vec){
        cout<<it<<" ";
    }
}
int main(){
    vector<int>vec={2,8,-1,-4,10,-10};
    sort(vec.begin(),vec.end());  //assending order
    // sort(vec.begin(),vec.end(),greater<int>());  //decending  order
    print(vec);
    
    return 0;
}