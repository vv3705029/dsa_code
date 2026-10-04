#include<iostream>
using namespace std;
class Car{
     //propeties
     //private
public://constructor
    Car(string name,string color){
        cout<<"constructor is called.object beng created."<<endl;
        this->name=name;
        this->color=color;
    }
    string name;
    string color;
    void start(){
        cout<<"car has started"<<endl;

    }
    void stop(){
        cout<<"car has stoped"<<endl;

    }
    //getter
    string getname(){
        return name;
    }
};
int main(){
    
    Car c1("maruti","red"); //object
    cout<<"Car name:"<<c1.getname()<<endl;
    return 0;
}