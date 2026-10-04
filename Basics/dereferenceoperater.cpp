#include<iostream>
using namespace std;
//pass by value
/*void changea(int a){
    a=20;
    cout<<a<<endl;
}*/


//pass by reference using pointer
void changea(int *ptr){
    *ptr=20;
}
int main(){
    //dereference oprator
    /*int a=10;
    int *ptr=&a;

    cout<<ptr<<endl;
    cout<<*(ptr)<<endl;

    *ptr=20;
    cout<<a;*/

    //null pointer
    /*int *ptr=NULL;
    cout<<ptr<<endl;
    cout<<*ptr<<endl;//segmentation error
    cout<<"vikas";*/
    
    //pass by value
    /*int a=10;
    changea(a);
    cout<<a;*/

    //pass by reference using pointer
    /*int a=10;
    changea(&a);
    cout<<a;*/

    //reference variable
    int a=10;
    int &b=a;
    b=25;
    cout<<b<<endl;
    cout<<a<<endl;
    return 0;
} 