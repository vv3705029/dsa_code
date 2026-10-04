#include<iostream>
using namespace std;
int main(){
    int arr[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    int n=3,m=3;
    int sum=0;
    /*for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==j){
                 sum+=arr[i][j];
            }else if (j==n-i-1)
            {
                sum+=arr[i][j];
            }
            
        }
    }
    cout<<"Sum of diagonal: "<<sum;
    //T.C=O(n^2)*/
    for(int i=0;i<n;i++){
        sum+=arr[i][i];
        if(i!=n-i-1){
            sum+=arr[i][n-i-1];
        }
    }
    cout<<"Sum of diagonal: "<<sum;
    //T.C=O(N)
    return 0;
}