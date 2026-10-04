#include<iostream>
#include<vector>
using namespace std;
//Using Recursion
int  countwayrec(int n){
    //Number of stairs
    if(n==0 || n==1){
        return 1;
    }
    return countwayrec(n-1)+countwayrec(n-2);
}
//Using Memobisation
int countBymemoization(int n,vector<int>&f){
    if(n==0 || n==1){
        return 1;
    }
    if(f[n]!=-1){
        return f[n];
    }
    f[n]=countBymemoization(n-1,f)+countBymemoization(n-2,f);
    return f[n];
}
//Using Tabulation
int countTabulation(int n,vector<int>&f){
    f[0]=1;
    f[1]=1;
    for(int i=2;i<=2;i++){
        f[i]=f[i-1]+f[i-2];
    }
    return f[n];
}
int main(){
    int stairs=3;
    vector<int>f(stairs+1,-1);
    cout<<"No of ways rec: "<<countwayrec(stairs)<<endl;
    cout<<"No of ways memoization: "<<countBymemoization(stairs,f)<<endl;
    cout<<"No of ways Tabulation: "<<countTabulation(stairs,f)<<endl;
    return 0;
}