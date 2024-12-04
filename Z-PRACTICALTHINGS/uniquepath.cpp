#include <iostream>
#include <vector>
using namespace std;
int main(){
    int row,col;
    cout<<"Enter the row :";
    cin>>row;
    cout<<"Enter the column :";
    cin>>col;
    int board[row+1][col+1];
    for(int i=0;i<=row;i++){
        board[i][0]=1;
    }
    for(int i=0;i<=col;i++){
        board[0][i]=1;
    }
    for(int i=1;i<=row;i++){
        for(int j=1;j<=col;j++){
            board[i][j]=board[i-1][j]+board[i][j-1];
        }
    }
    cout<<"The last position possible value is :"<<board[row][col];
}