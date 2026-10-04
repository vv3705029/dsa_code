
//question no 1 ApplyMergesorttosortanarrayofStrings
/*#include<iostream>
#include<string>
#include<vector>
using namespace std;
void merge(string arr[],int si,int mid,int ei){
    vector<string>temp;
    int i=si;
    int j=mid+1;
    while(i<=mid && j<=ei){
         if(arr[i]<=arr[j]){
            temp.push_back(arr[i++]);
         }else{
            temp.push_back(arr[j++]);
         }
    }
    while(i<=mid){
        temp.push_back(arr[i++]);
    }
    while (j<=ei)
    {
        temp.push_back(arr[j++]);
    }
    //vector to arr copy
    for(int idx=si, x=0;idx<=ei;idx++){
        arr[idx]=temp[x++];
    }

}
void mergesort(string arr[],int si,int ei){    
    if(si>=ei){
        return ;
    }
    int mid=si+(ei-si)/2;
    mergesort(arr,si,mid);//left half
    mergesort(arr,mid+1,ei);//right half

    merge(arr,si,mid,ei);
}
void printarr(string arr[],int n){
    for(int i=0;i<n;i++){
       cout<<arr[i]<<" ";
    }
}

int main(){
    string arr[]={"sun","earth","mars","mercury"};
    int n=sizeof(arr)/sizeof(string);
    mergesort(arr,0,n-1);
    printarr(arr,n);
    
    return 0;
}
*/

//Question no 2 Givenanarraynumsofsizen,returnthemajorityelement.
/*#include<iostream>
using namespace std;
void count(int arr[],int n){
    int arr1[n-1]={};

}
int main(){
    int arr[]={2,2,1,1,1,2,2};
    int n=sizeof(n)/sizeof(int);
    
    return 0;
}*/

//question no 3 Givenanarrayofintegers.FindtheInversionCountinthearray
#include<iostream>
#include<vector>
using namespace std;
int  merge(int arr[],int left,int mid,int right){
    vector<int> temp;
    int i=left;
    int j=mid+1;
    int invcount =0;
    while(i<=mid && j<=right){
         if(arr[i]<=arr[j]){
            temp.push_back(arr[i++]);
         }else{
            temp.push_back(arr[j++]);
            invcount+=(mid-i);
         }
    }
    while(i<=mid){
        temp.push_back(arr[i++]);
    }
    while (j<=right)
    {
        temp.push_back(arr[j++]);
    }
    //vector to arr copy
    for(int x=left,k=0;x<=right;x++,k++){
        arr[x]=temp[k];
    }
    return invcount;
}
int mergesort(int arr[],int left,int right){
    int invcount;
    if(right>left){
        int mid=(left+right)/2;
        invcount=mergesort(arr,left,mid);
        invcount=mergesort(arr,mid+1,right);
        invcount+=merge(arr,left,mid+1,right);
    };
    return invcount;
}
int getinversions(int arr[], int n){
    return mergesort(arr,0,n-1);
}
int main(){
    int arr[]={4,1,3,6};
    int n=sizeof(arr)/sizeof(int);
    cout<<"Inversion count :"<<getinversions(arr,n);
    return 0;
}