#include<iostream>
#include <vector>
using namespace std;
int main(){
    /*vector<int>vec1;
    vector<int>vec2={1,3,2};
    vector<int>vec3{(3,4,2)};
    vector<int>vec4(4,-4);
    cout<<vec2.size()<<endl;
    for(int i=0;i<vec2.size();i++){
        cout<<vec2[i]<<endl;
    }*/



    //capacity
    vector<int>vec5={1,2,3,4,5};
    cout<<"Size:"<<vec5.size()<<endl;
    cout<<"Cap: "<<vec5.capacity()<<endl;
    vec5.push_back(6);
    cout<<"Size:"<<vec5.size()<<endl;
    cout<<"Cap: "<<vec5.capacity()<<endl;//capacity dobuled
    return 0;
}