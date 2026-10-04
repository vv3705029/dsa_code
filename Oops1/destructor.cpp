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
        *mileage=*original.mileage;
    }

    //destructor
    ~Car(){
       cout<<"deleting object."<<endl; 
       if(mileage != NULL){
        delete mileage;
        mileage=NULL;
       }
    }
};
int main(){
    
    Car c1("maruti","red");
    cout<<c1.name<<endl;
    cout<<c1.color<<endl;
     cout<<*(c1.mileage)<<endl;
    return 0;
}