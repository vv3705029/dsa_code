#include<iostream>
using namespace std;
int setbit(int num){
    int count=0;
    
    while(num>0){
        count+=(num&1);
        num>>=1;
    
    }
    cout<<count;
}
int main(){
    setbit(15);
    // cout<<(2>>0);
    return 0;
}