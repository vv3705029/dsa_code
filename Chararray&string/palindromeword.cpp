#include<iostream>
#include<cstring>
using namespace std;
/*bool palindrome(char word[],int n){
    int st=0,end=n-1;
    while(st<end){
        if(word[st++]!=word[end--]){
            return false;
        }
    }
    return true;
}*/
int main(){
    /*char word[]="viv";
    cout<<palindrome(word,strlen(word));*/
    char str1[100];
    char str2[]="hello world";
    //str1="vikas";
    strcpy(str1,"avikas");
    cout<<str1<<endl;
    //strcpy(str1,str2);
    cout<<str1<<endl;
    strcat(str1,str2);
     cout<<str1<<endl;
    cout<<strcmp(str1,str2);
    return 0;
}