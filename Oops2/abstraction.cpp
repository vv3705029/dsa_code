#include<iostream>
#include<string>
using namespace std;
// Abstraction on cpp is the process of hinding  the implimentation details and only
// showing the essential details or features to the user.
class Shape{
public:
    virtual void draw()=0;//pure virtual class
};
class Circle: public Shape{
public:
    void draw(){
        cout<<"draw a circle."<<endl;
    }
};
class Square:public Shape{
public:
    void draw(){
        cout<<"draw a square."<<endl;
    }
};
int main(){
    Circle c1;
    c1.draw();
    Square s1;
    s1.draw();
    return 0;
}