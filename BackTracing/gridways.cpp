#include<iostream>
#include<vector>
using namespace std;
int gridways(int r,int c,int n,int m,string ans){
    if(r==n-1 && c==m-1){
        cout<<ans<<endl;
        return 1;
    }
    if(r>=n || c>=m){
        return 0;
    }
    int v1=gridways(r,c+1,n,m,ans+"R");//right
    int v2=gridways(r+1,c,n,m,ans+"D");//down
    return v1+v2;
}
int main(){
    cout<<"Number of ways:"<<gridways(0,0,3,3,"");
}