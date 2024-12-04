#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int row, int col, vector<vector<int>>&board, int N){
    for(int i=0;i<N;i++){
        if(board[i][col]==1)
            return false;
    }
    
    for(int i=row,j=col;i>=0&&j>=0;i--,j--){
        if(board[i][j]==1){
            return false;
        }
    }
    for(int i=row,j=col;i>=0&&j<N;i--,j++){
        if(board[i][j]==1)
            return false;
    }
    return true;
}

bool SolveNQueen(int row, vector<vector<int>>&board, int N){
    if(row==N){
        return true;
    }
    for(int col=0;col<N;col++){
        if(isSafe(row,col,board,N)){
            board[row][col]=1;
            if(SolveNQueen(row+1,board,N))
                return true;
            board[row][col]=0;
        }
    }
        return false;
}

int main(){
    
    int size;
    cout<<"Enter the size :";
    cin>>size;
    vector<vector<int>>board(size,vector<int>(size,0));
    SolveNQueen(0,board,size);
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            cout<<board[i][j]<<' ';
        }
        cout<<"\n";
    }
   
    
}