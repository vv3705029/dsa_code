#include<iostream>
using namespace std;
class Car{
public://constructor
    Car(string name,string color){
        this->name=name;
        this->color=color;
    }
    string name;
    string color;
    //custom copy constructor
    Car(Car &original){
        cout<<"copying original to new."<<endl;
        name=original.name;
        color=original.color;
    }
};
int main(){
    
    Car c1("maruti","red");
    Car c2(c1); //object
    cout<<c2.name<<endl;
    cout<<c2.color<<endl;
    
    return 0;
}