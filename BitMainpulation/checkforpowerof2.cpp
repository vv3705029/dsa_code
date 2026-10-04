#include<iostream>
using namespace  std;
int checkpower(int num){
    if((num)&(num-1)==0){
        cout<<"power of 2";
    }
    else{
        cout<<"Not power of 2";
    }
    
}
int main(){
    checkpower(3);
    cout<<endl;
    cout<<(1<<2);
    return 0;
}