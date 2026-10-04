#include<iostream>
using namespace std;
class Student{
     //propeties
     //private
public:
     string name;
     float cgpa;
     //method
     void getper(){
        cout<<(cgpa*10)<<"%"<<endl;

     }
};
int main(){
    Student s1; //object
    s1.name="vikas";
    s1.cgpa=9.0;
    cout<<s1.cgpa<<endl;
    s1.getper();
    return 0;
}