#include<iostream>
using namespace std;
/*int pow(int x,int n){
    if(n==0){
        return 1;
    }
    return x*pow(x,n-1);
}*/
 

//time complexcity log(n)
int pow(int x,int n){
    if(n==0){
        return 1;
    }
    int halfpow=pow(x,n/2);
    int halfpowsquare=halfpow*halfpow;
    if(n%2!=0){
        return x*halfpowsquare;
    }
    return halfpowsquare;
}
int main(){
    cout<<pow(2,5);
    return 0;
}