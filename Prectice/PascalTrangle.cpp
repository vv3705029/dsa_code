#include<iostream>
#include<vector>
using namespace std;
int main(){
    int row;
    cin>>row;
    vector<vector<int>>ans;
    ans.push_back({1});
    ans.push_back({1,1});
    
    for(int i=2;i<row;i++){
        vector<int>temp;
        temp.push_back(1);
        for(int j=0;j<i-1;j++){
            int x=ans[i-1][j]+ans[i-1][j+1];
            temp.push_back(x);
        }
        temp.push_back(1);
        ans.push_back(temp);
    }



    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}