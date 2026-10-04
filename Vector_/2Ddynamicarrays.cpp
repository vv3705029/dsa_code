#include<iostream>
#include<vector>

using namespace std;
int main(){
    vector<vector<int>>matrix;
    int row,col;
    cin>>row>>col;
    for(int i=0;i<row;i++){
        vector<int>temp;
        for(int j=0;j<col;j++){
            int x;
            cin>>x;
            temp.push_back(x);
        }
        matrix.push_back(temp);
        temp.clear();
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<'\n';
    }
    return 0;
}