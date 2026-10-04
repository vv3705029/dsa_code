#include<iostream>
using namespace std;

//Question no1
/*int pailndrome(int n){
    int sum=0;
    while (n>0)
    {
     int rem=n%10;
        sum=sum*10+rem;
        n=n/10;   
    }
    return sum;
}
int main(){
    cout<<pailndrome(1544641);
    return 0;
}*/

//Question no 2
/*int sum(int n){
    int sum=0;
    while(n>0){
        int d=n%10;
        sum+=d;
        n=n/10;
    }
    return sum;
}
int main(){
    cout<<"Sum of digits: "<<sum(213);
    return 0;
}*/


//Question no 3
/*int result(int a,int b){
    int sum=a*a+b*b+2*a*b;
    return sum;
}
int main(){
    cout<<"Result: "<<result(3,2);
    return 0;
}*/

//Question no 4
/*char characte(char ch){
    if(ch=='z'){
        return 'a';
    }else{
        return ch+1;
    }
}
int main(){
    
    cout<<characte('b');
    return 0;
}*/


int main(){
    cout<<sizeof(int)<<endl;
    cout<<sizeof(long long int)<<endl;
    cout<<sizeof(short int)<<endl;
    return 0;
}