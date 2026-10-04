#include<iostream>
using namespace std;
int main(){
    float  math;
    float eng;
    float his;
    cout<<"enter math marks:";
    cin>>math;
    cout<<"enter eng mark:";
    cin>>eng;
    cout<<"enter his mark :";
    cin>>his;
    float avg=(math+eng+his)/3;
    cout<<"avg mark:"<<avg;


    return 0;

}