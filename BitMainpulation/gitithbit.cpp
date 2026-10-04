#include<iostream>
using namespace std;
int number(int num,int i){
    int bitmask=1<<i;
    if((num&bitmask)==0){
        return 0;
    }else{
        return 1;
    }
}
int main(){
    cout<<number(6,1);
    return 0;
}