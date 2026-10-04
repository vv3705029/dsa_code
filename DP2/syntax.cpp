#include<iostream>
using namespace std;
class Student{
     //Propertie
      float cgpa;
      string name;
public:
     //method
     void getpercentage(){
        cout<<(cgpa*10)<<"%"<<endl;
     }
     //setters
     void setname(string nameval){
        name=nameval;
     }
     void setcgpa(float cgpaval){
        cgpa=cgpaval;
     }

     //getters
     string getname(){
        return name;
     }
     int getcgpa(){
        return cgpa;
     }
};
int main(){
    Student s1;//object
    /*cout<<sizeof(s1)<<endl;
    s1.name="vikas";
    s1.cgpa=9.0;
    cout<<s1.name<<endl;
    cout<<s1.cgpa<<endl;
    s1.getpercentage();*/

    //setters call
    s1.setname("vikas");
    s1.setcgpa(9.1);
    
    //getters call
    /*cout<<s1.getname()<<endl;
    cout<<s1.getcgpa()<<endl;*/
    return 0;
}