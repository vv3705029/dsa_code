#include<iostream>
using namespace std;
int exponentiation(int x,int n){
      int ans=1;
      while(n>0){
        int lastbit=n&1;
        if(lastbit!=0){
            ans=ans*x;
        }
        x=x*x;
        n=n>>1;
      }
      cout<<ans;
}
int main(){
   exponentiation(2,4);
    return 0;
}