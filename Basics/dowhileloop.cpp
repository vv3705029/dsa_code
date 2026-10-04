#include<iostream>
using namespace std;
int main(){
    /*int i=1;
    do
    {
        cout<<i<<" ";
        i+=1;
        if(i==3){
            break;
        }
    } while (i<=5);*/

    //WAP where user can keep entering number till they enter a multiple of 10
    int n;
    do
    {
        cout<<"Enter number:";
        cin>>n;
        if(n%10==0){
            break;
        }
        cout<<"YOU enter:"<<n<<endl;
    } while (true);
    cout<<"You enter the multipel of 10.";
    
    return 0;
}
//work gets done atleast once irrespective of condition
