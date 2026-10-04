#include<iostream>
using namespace std;
int main(){
    int a=21;
    int *ptr=&a;
    int **pptr=&ptr;
    
    cout<<&ptr<<"="<<pptr<<endl;
    cout<<*(ptr)<<endl;

    float pi=3.14;
    float *ptr1=&pi;
    
    cout<<sizeof(ptr)<<endl;
    cout<<(*ptr1)++<<endl;
    cout<<*ptr1<<endl;

    cout<<&a<<"="<<ptr<<endl;
    cout<<&pi<<"="<<ptr1<<endl;
    return 0;
}