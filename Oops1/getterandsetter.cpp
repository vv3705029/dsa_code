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

     //setter
     void setname(string nameval){
        name=nameval;
     }
     void setcgpa(float cgpaval){
        cgpa=cgpaval;
     }

    //getter
    string getname(){
        return name;
     }
    float getcgpa(){
        return cgpa;
     }

};
int main(){
   Student s1; //object
   s1.setname("vikas");
   s1.setcgpa(9.0);
    
   cout<<s1.getname()<<endl;
    cout<<s1.getcgpa()<<endl;

    s1.getname();
   return 0;
}