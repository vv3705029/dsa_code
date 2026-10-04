#include<iostream>
using namespace std;
class Car{
    public:
    string name;
    string color;
    Car(string name,string color){
        this->name=name;
        this->color=color;
    }
    //copy constructor
    Car(Car &original){
        cout<<"Copy original to new."<<endl;
        name=original.name;
        color=original.color;
    }
};
int main(){
    Car c1("Maruti","White");
    Car c2(c1);
    cout<<"Car :"<<c2.name<<endl;
    cout<<"color:"<<c2.color<<endl;
    return 0;
}