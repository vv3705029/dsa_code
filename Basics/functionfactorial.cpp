#include<iostream>
using namespace std;
int factorail(int a){
    int fact=1;
    for(int i=0;i<a;i++){
        fact=fact*(i+1);
        
    }
    return fact;
}
int main(){
    cout<<"factorail of a:"<<factorail(25);
    return 0;
}