#include<iostream>
#include<vector>
using namespace std;
int print(int sudoko[9][9]){
     for(int i=0;i<9;i++){
          for(int j=0;j<9;j++){
              cout<<sudoko[i][j]<<" ";
          }
          cout<<endl;
     }
}
bool issafe(int sudoko[][9],int row,int col,int dig ){
    //vertical
    for(int i=0;i<=8;i++){
        if(sudoko[i][col]==dig){
            return false;
        }
    }
    //horzontal
    for(int i=0;i<=8;i++){
        if(sudoko[row][i]==dig){
            return false;
        }
    }
    //3*3 grid
    int startrow=(row/3)*3;
    int startcol=(col/3)*3;
    for(int i=startrow;i<=startrow+2;i++){
        for(int j=startcol;j<=startcol+2;j++){
            if(sudoko[i][j]==dig){
                return false;
            }
        }
    }
    return true;
}
bool sudokusolver(int sudoku[9][9],int row,int col){
    if(row==9){
        print(sudoku);
        return true;
    }
    int nextrow=row;
    int nextcol=col+1;
    if(col+1==9){
        nextrow=row+1;
        nextcol=0;
    }
    if(sudoku[row][col]!=0){
        return   sudokusolver(sudoku,nextrow,nextcol);

    }
    for(int dig=1;dig<=9;dig++){
        if(issafe(sudoku,row,col,dig)){
            sudoku[row][col]=dig;
            if(sudokusolver(sudoku,nextrow,nextcol)){
                return true;
            };
            sudoku[row][col]=0;

        }
    }
    return false;
}
int main(){
    int sudoku[9][9] = {{0,0,8,0,0,0,0,0,0},
                        {4,9,0,1,5,7,0,0,2},
                        {0,0,3,0,0,4,1,9,0},
                        {1,8,5,0,6,0,0,2,0},
                        {0,0,0,0,2,0,0,6,0},
                        {9,6,0,4,0,5,3,0,0},
                        {0,3,0,0,7,2,0,0,4},
                        {0,4,9,0,3,0,0,5,7},
                        {8,2,7,0,0,9,0,1,3}
    };
    cout<<sudokusolver(sudoku,0,0);
}