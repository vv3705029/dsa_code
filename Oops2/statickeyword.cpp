#include<iostream>
#include<string>
using namespace std;
//function static 
/*void counter(){
    static int count=0;
    count++;
    cout<<"count :"<<count<<endl;
}
int main(){
    counter();
    counter();
    return 0;
}*/
//class static
/*class Example{
public:
    static int  x;
};
int Example::x=0;
int main(){
     Example e1;
      Example e2;
     Example e3;
     cout<<e1.x++<<endl;
     cout<<e2.x++<<endl;
     cout<<e3.x++<<endl;
    return 0;
}**/

//static object
class Example{
public:
    Example(){
        cout<<"constructor"<<endl;
    }
    ~Example(){
        cout<<"destructor"<<endl;
    }
};
int main(){
    int a=0;
    if (a==0){
        static Example e1;
    }
    cout<<"code ending"<<endl;
    return 0;
}