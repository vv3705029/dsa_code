#include<iostream>
using namespace std;

//Question no-1
/*int number(int arr[][3],int n,int m,int key){
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==key){
                count++;
            }
        }
    }
    return count;
}
int main(){
    int arr[2][3]={{4,7,8},{8,8,7}};
    int n=2,m=3;
    cout<<number(arr,n,m,7);
    return 0;
}*/

//Question no-2  sum of second row
/*int sumnums(int nums[][3],int n,int m){
    int sum=0;
    for(int i=0;i<m;i++){
        sum+=nums[1][i];
    }
    cout<<"Sum of 2nd row: "<<sum;
}
int main(){
    int nums[3][3]={{4,7,8,},{11,4,3},{2,2,3}};
    int n=3,m=3;
    sumnums(nums,n,m);
    return 0;
}*/

//Question no-3  transpose of matrix

/*int main(){
    int n=3,m=3;
    int nums[n][m]={{4,7,8,},{11,4,3},{2,2,3}};
    int trans[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            swap(nums[i][j],trans[j][i]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<trans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}*/

//Question no-4 using a id array form a 2D array
/*int main(){
    int m=2,n=2;//n number of rows , m number of columan
    int original[]={1,2,3,4};
    int arr[n][m];
    int arr1[m];
    for(int i=0;i<n;i++){
        int arr1[m];
        for(int j=0;j<m;j++){
            
        }
    }
    
}*/



//Question no=5
int main(){
    int n=3;
    int arr[n][n]={{1,2,3,},{4,5,6},{7,8,9}};
    int out[n][n];
    int en=n-1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            out[j][en]=arr[i][j];
        }
        en--;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<out[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
