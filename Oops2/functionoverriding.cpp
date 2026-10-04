#include<iostream>
#include<string>
using namespace std;
class Parent{
public://function overriding 
     
     void show(){
        cout<<"parent class show."<<endl;
     }//virtual function
     virtual void hello(){
        cout<<"parent hello."<<endl;
     }
};
class Child:public Parent{
public:
    void show(){
        cout<<"child class show."<<endl;
    }
     void hello(){
        cout<<"parent hello."<<endl;
     }
};
int main(){
    Child c1;
    //virtual function
    Parent *ptr;
    ptr=&c1;//run time binding
    ptr->hello(); //virtual function 
    return 0;
}