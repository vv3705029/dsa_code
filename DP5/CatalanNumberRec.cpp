#include<iostream>
using namespace std;
int cataRec(int n){
    if(n==0 || n==1){
        return 1;
    }
    int ans=0;
    for(int i=0;i<n;i++){
        ans+=cataRec(i)*cataRec(n-i-1);
    }
    return ans;
}
 int main(){
    int n=5;//nth catalan's number
    for(int i=0;i<n;i++){
        cout<<cataRec(i)<<" ";
    }
    return 0;

 }