#include<iostream>
#include<vector>
using namespace std;
int lastoccurance(vector<int>arr,int i,int target){
    if(i==arr.size()){
        return -1;
    }
    if(target==arr[arr.size()-i-1]){
         return arr.size()-i-1;
    }
    return lastoccurance(arr,i+1,target);

}
int main(){
    vector<int>arr={1,2,3,3,3,4};
    cout<<lastoccurance(arr,0,4);
    return 0;
}