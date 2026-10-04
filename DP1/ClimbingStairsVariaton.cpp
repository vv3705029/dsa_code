// Only three jumps 1,2,3 allowed
#include<iostream>
#include<vector>
using namespace std;

int countTabulation(int n){//O(n)
     vector<int>f(n+1,0);
    f[0]=1;
    f[1]=1;
    f[2]=2;
    for(int i=3;i<=n;i++){
        f[i]=f[i-1]+f[i-2]+f[i-3];
    }
    return f[n];
}
int main(){
    int stairs=3;
    cout<<"No of ways Tabulation: "<<countTabulation(stairs)<<endl;
    return 0;
}