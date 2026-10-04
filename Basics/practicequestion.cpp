#include<iostream>
using namespace std;
class User{
private:
    int id;
    string password;
public:
    string username;
    User(int id){
        this->id=id;
    }
    //getter
    string getpassword(){
        return password;
    }
    //setter
    void setpassword(string password){
        this->password=password;
    }
};
int main(){
    User u1(101);
    u1.username="vikas verma";
    u1.setpassword("vikas0");
    cout<<"Username: "<<u1.username<<endl;
    cout<<"password: "<<u1.getpassword()<<endl;
    return 0;
}