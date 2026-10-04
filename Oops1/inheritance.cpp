#include<iostream>
using namespace std;

//Multi lable inheritance

class Animal{  //Super class
public:
    Animal(){
        cout<<"Animal constructor is called."<<endl;
    }
    string color;
    void eat(){
        cout<<"eat"<<endl;
    }
    void breathe(){
        cout<<"breathes"<<endl;
    }
};
class Mammal: public Animal{  //Sub class
public:
    string bloodtype;
    Mammal(){
        cout<<"Mammal constructor is called ."<<endl;
        bloodtype="worm";
    }
};
class Dog:public Mammal { // Sub class
public:
    Dog(){
        cout<<"Dog constructor is called ."<<endl;
    }
    int fins;
    void tailwag(){
        cout<<"A dog wags its tail."<<endl;
    }
};
int main(){
    Dog d1;
    d1.eat();
    d1.breathe();
    return 0;
}