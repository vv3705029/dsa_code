#include<iostream>
#include<string>
using namespace std;

//Question no 1 using operator overloading create the logic to subtract one complex to another.
/*class Complex{
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
}*/

//Question no2 CreateaclassBankAccountwithprivateattributesaccountNumberandbalance.Implementpublicmethodsdeposit(),withdraw(),andgetBalance()tomanagetheaccount.

/*class Bankaccount{
private:
    string accountnumber;
    int balance;
public:
    void deposit(){
        cout<<"Account is deposited."<<endl;
    }
    void withdraw(){
        cout<<"Money withdrawing."<<endl;
    }
    void getbalance(){
        cout<<"1200.00"<<endl;
    }
};
int main(){
    Bankaccount c1;
    c1.deposit();
    c1.withdraw();
    c1.getbalance();
    return 0;
}*/

//Question no 3 CreateabaseclassPersonwithattributesnameandage.DeriveaclassStudentfromPersonandaddanadditionalattributestudentID.ImplementamethoddisplayStudentInfo()intheStudentclasstodisplayalldetails

class Persion{
protected:
    string name;
   int age;
public:
   Persion(string n,int a){
       name=n;
       age=a;
   }
};
class Student:public Persion{
private:
   string studentid;
public:
   Student(string n,int a,string id):Persion (n,a){
     studentid=id;
   }
   void displastudentinfo(){
      cout<<this->name<<endl;
      cout<<this->age<<endl;
      cout<<this->studentid<<endl;
   }
};
int main(){
    Student student("vikas",20,"djgwdw");
    student.displastudentinfo();
    return 0;
}