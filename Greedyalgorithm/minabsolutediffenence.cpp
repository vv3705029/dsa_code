#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool compare(pair<int,int>p1,pair<int,int>p2){
    return p1.second<p2.second;//end
}
int main(){
    vector<int>A={4,1,8,7};
    vector<int>B={2,3,6,5};

    int n=A.size();
    int minsum=0;

    sort(A.begin(),A.end());
    sort(B.begin(),B.end());

    for(int i=0;i<n;i++){
        // if(A[i]>B[i]){
        //     minsum+=A[i]-B[i];
        // }else{
        //     minsum+=B[i]-A[i];
        // }
        minsum+=(A[i]>=B[i])?A[i]-B[i]:B[i]-A[i];
    }
    cout<<minsum;
    return 0;
}