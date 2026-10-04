#include<iostream>
using namespace std;
class Car{
public://constructor
    Car(string name,string color){
        this->name=name;
        this->color=color;
        mileage=new int;//dynamic allocation
        *mileage=12;
    }
    string name;
    string color;
    int *mileage;

    //custom copy constructor
    Car(Car &original){
        cout<<"copying original to new."<<endl;
        name=original.name;
        color=original.color;
        mileage=new int;
        mileage=original.mileage;
    }
};
int main(){
    
    Car c1("maruti","red");
    Car c2(c1); //object
    cout<<c2.name<<endl;
    cout<<*(c2.mileage)<<endl;
    *c2.mileage=10;
     cout<<*(c1.mileage)<<endl;
    return 0;
}