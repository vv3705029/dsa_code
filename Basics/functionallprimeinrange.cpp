#include<iostream>
using namespace std;
int prime(int n){
    for(int i=2;i<=n;i++){
        if(n%i==0){
            return 1;
        }else{
            return 0;
        }
    }
}
int main(){
    
    return 0;
}