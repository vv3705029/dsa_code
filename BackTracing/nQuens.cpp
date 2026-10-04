#include<iostream>
#include<vector>
using namespace std;
void print(vector<vector<char>> board){
      for(int i=0;i<board.size();i++){
        for(int j=0;j<board.size();j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
      }
      cout<<"--------"<<endl;
}
bool issafe(vector<vector<char>> board,int row,int col){
    int n=board.size();
    //horizontal
    for(int j=0;j<n;j++){
        if(board[row][j]=='Q'){
            return false;
        }
    }
    //vertial
    for(int i=0;i<row;i++){
        if(board[i][col]=='Q'){
            return false;
        }
    }
    //diagonal left
    for(int i=row,j=col;i>=0 &&j>=0;i--,j--){
         if(board[i][j]=='Q'){
            return false;
        }
    }
    //right di
    for(int i=row,j=col;i>=0 &&j<n;i--,j++){
         if(board[i][j]=='Q'){
            return false;
        }
    }

    return true;

}
int  nqueens(vector<vector<char>> board,int row){
    int n=board.size();
    if(row==n){
        print(board);
        return 1;
    }
    int count=0;
    for(int j=0;j<n;j++){
        if(issafe(board,row,j)){
            board[row][j]='Q';
            count+= nqueens(board,row+1);
            // if(count==1){
            //     return count;
            // }
            board[row][j]='.';
        }
    }
    return count;//number of possible solution
}
int main(){
    vector<vector<char>>board;
    int n=4;
    for(int i=0;i<n;i++){
        vector<char>newrow;
        for(int j=0;j<n;j++){
            newrow.push_back('.');
        }
        board.push_back(newrow);
    }
   
   
    int count=nqueens(board,0);
    cout<<"count:"<<count<<endl;

}