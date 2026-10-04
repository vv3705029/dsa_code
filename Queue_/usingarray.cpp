#include<iostream>
using namespace std;
class Queue{
   int* arr;
   int capacity;//or real size of the arr
   int currsize;
   int f,r;//front and back pointer
public:

     Queue(int capaciy){
        this->capacity=capacity;
        arr=new int[capacity];
        currsize=0;
        f=0;
        r=-1;
        cout<<"constructor is called;"<<endl;
     }
     void push(int data){
        if(currsize==capacity){
            cout<<"Queue is full"<<endl;
            return ;
        }
          r=(r+1)%capacity;
          arr[r]=data;
          currsize++;
     }
     void pop(){
        if(empty()){
            cout<<"Queue is full"<<endl;
            return ;
        }
        f=(f+1)%capacity;
        currsize--;
     }
     int front(){
         if(empty()){
            cout<<"Queue is full"<<endl;
            return -1;
        }
        return arr[f];
     }
     bool empty(){
        return currsize==0;
     }
     void printrear(){
        cout<<arr[r]<<endl;
     }

};
int main(){
    Queue q(4);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.printrear();
 
 
    cout<<q.front()<<endl;
    return 0;
}