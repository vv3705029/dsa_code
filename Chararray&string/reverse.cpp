#include<iostream>
#include<cstring>
using namespace std;
void reverse(char word[],int n){
    for(int i=0;i<(n/2);i++){
        swap(word[i],word[n-i-1]);
    }
    cout<<word;
}
int main(){
    char word[]="vikas";
    reverse(word,strlen(word));
    return 0;
}