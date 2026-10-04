#include<iostream>
#include<list>
#include<iterator>
using namespace std;
void printlist(list<int>ll){
   list<int>::iterator itr;
    for( itr=ll.begin();itr!=ll.end();itr++){
          cout<<*(itr)<<"->";
    }
    cout<<"NULL"<<endl;
}
int main(){
    list<int>ll;

    ll.push_front(2);
    ll.push_front(1);
    ll.push_back(3);
    printlist(ll);
    cout<<ll.size()<<endl;
    cout<<"head :"<<ll.front()<<endl;
    ll.pop_back();
    printlist(ll);
    return 0;
}