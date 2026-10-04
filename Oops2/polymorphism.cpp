#include<iostream>
#include<string>
using namespace std;

//function overloding
/*class Print{
public:
     void show(int x){
        cout<<"int :"<<x<<endl;
     }
     void show(string str){
        cout<<"str :"<<str<<endl;
     }
};
int main(){
    Print o1;
    o1.show(3);
    o1.show("vikas verma");
    return 0;
}
*/

//operator overloding


class Complex{
    int real;
    int img;
public:
    Complex(int r,int i){
        real=r;
        img=i;
    }
    void shownum(){
        cout<<real<<"+"<<img<<"i"<<endl;
    }
    Complex operator - (Complex &c2){
        int resreal=this->real-c2.real;
        int resimg=this->img-c2.img;
        Complex c3(resreal,resimg);
        return c3;
    }
};
int main(){
    Complex c1(8,9);
    Complex c2(4,7);
    c1.shownum();
    c2.shownum();

    Complex c3=c1-c2;
    c3.shownum();
    return 0;
}