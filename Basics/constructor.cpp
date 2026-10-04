#include<iostream>
using namespace std;
class Car{
    string name;
    string color;
public:
    Car(){
      cout<<"Constructor is called .Without parameter."<<endl;  
    }
    Car(string nameval,string colorval){
       cout<<"Constructor is called .Object being created."<<endl;
       this->name=name;
       this->color=color;
    }
     void start(){
        cout<<"Car has start"<<endl;

     }
     void stop(){
        cout<<"Car has stop"<<endl;
     }
     //getter
     string getname(){
        return name;
     }
    string getcolor(){
        return color;
    }
};
int main(){
    Car c0;
    Car c1("maruti","while");
    c1.start();
    cout<<"Car name: "<<c1.getname()<<endl;
     cout<<"Car color: "<<c1.getcolor()<<endl;
    return 0;
}