#include<iostream>
using namespace std;
/*int setithbit(int num,int i){
    int bitmask=~(1<<i);
    return (num & bitmask);
}*/

void updateithbit(int num,int i,int val){
    num=num& ~(1<<i);
    num=num|(val<<i);
    cout<<num<<endl;
}
int main(){
    //cout<<setithbit(7,2);
    updateithbit(7,2,0);
    return 0; 
}