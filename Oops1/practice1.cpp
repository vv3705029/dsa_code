#include<iostream>
using namespace std;
class User{
    
private:
    int  id;
    string password;
public:
    string username;
    User(int  id){
        cout<<"constructor is called"<<endl;
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
    User u1(100);
    u1.username="apnacollage";
    u1.setpassword("bhj");
    cout<<"username:"<<u1.username<<endl;
    return 0;
}