#include<iostream>
#include<vector>
using namespace std;
//Using Recursion
int fib(int n){//O(2^n)
    if(n==0 || n==1){
        return n;
    }
    return fib(n-1)+fib(n-2);
}
//Using Memobisation
int fibDP(int n,vector<int>&f){//O(n)
    if(n==0 || n==1){
        return n;
    }
    if(f[n]!=-1){
        return f[n];
    }
    f[n]=fibDP(n-1,f)+fibDP(n-2,f);
    return f[n];
}
//Using Tabulation

int faiTabulation(int n){
    vector<int>fib(n+1,0);
    fib[0]=0;
    fib[1]=1;
    for(int i=2;i<=n;i++){
        fib[i]=fib[i-1]+fib[i-2];
    }
    return fib[n];
}
int main(){
    int n=3;
    vector<int>f(n+1,-1);
    cout<<fibDP(n,f)<<" "<<endl;
    cout<<faiTabulation(n);
    return 0;
}