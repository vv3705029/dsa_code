# include<iostream>
using namespace std;
class Teacher{
public: 
    Teacher(){
        cout<<"Teacher constructor is called."<<endl;
    }
    int salary;
    string subject;
};
class Student {
public:
    Student(){
        cout<<"Student constructor is called."<<endl;
    }
    int rolluo;
    float cgpa;
};
class Ta:public Student,public Teacher{
public:
    Ta(){
        cout<<"Ta constructor is called."<<endl;
    }
    string name;
};
int main(){
    Ta  ta1;
    ta1.name="vikas";
    ta1.subject="C++";
    cout<<ta1.name<<endl;
    cout<< ta1.subject<<endl;
    
    return 0;
}
