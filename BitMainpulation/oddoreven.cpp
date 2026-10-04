#include<iostream>
using namespace std;
void number(int num){
    if((num & 1)==0){
        cout<<"even"<<endl;
    }
    else{
        cout<<"odd";
    }
}
int main(){
    number(2);
     number(3);
    return 0;
}