#include<iostream>
#include<string>
#include<queue>
#include<vector>
using namespace std;
class Student{//"<"overload
public:
    string name;
    int marks;
    Student(string name,int marks){
        this->name=name;
        this->marks=marks;
    }
    bool operator < (const Student &obj)const{//overload comparater function
        return this->marks < obj.marks;//for min heap use >
    }
};
int main(){
    priority_queue<Student>pq;
    pq.push(Student("vikas",34));
    pq.push(Student("neha",45));
    pq.push(Student("aman",40));
    while(!pq.empty()){
        cout<<pq.top().name<<" : "<<pq.top().marks<<endl;
        pq.pop();
    }
    return 0;
}