#include<iostream>
#include<vector>

using namespace std;
void printprofit(vector<int>prices,int n){
    
    int minSofar=prices[0];
    int res=0;
    for(int i=1;i<n;i++){
        
        minSofar=min(prices[i],minSofar);
        res=max(res,prices[i]-minSofar);
    }

    cout<<"Max Profit : "<<res;
}
int main(){
    vector<int>prices={7,1,5,3,9,4};
    int n=prices.size();
    printprofit(prices,n);
    return 0;
}