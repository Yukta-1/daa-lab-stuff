#include <stdbool.h>
#include <stdio.h>
#include <iostream>
using namespace std;

void printSolution(int** board,int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++){
            if(j==n-1){
                cout<< board[i][j];
            }
            else{
                cout<< board[i][j]<<" ";
            }
        }
        cout<<"\n";
    }
}
 
bool isSafe(int** board, int row, int col,int n)
{
    int i, j;
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;
    for (i = row, j = col; j >= 0 && i < n; i++, j--)
        if (board[i][j])
            return false;
 
    return true;
}

bool solveNQUtil(int** board, int col,int n)
{
    if (col >= n)
        return true;
    for (int i = 0; i < n; i++) {
        if (isSafe(board, i, col,n)) {
            board[i][col] = 1;
            if (solveNQUtil(board, col + 1,n))
                return true;
            board[i][col] = 0; 
        }
    }
    return false;
}
bool solveNQ(int n)
{
    int** board = new int*[n];
 
    for (int i = 0; i < n; i++) {
        board[i] = new int[n];
    }
 
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            board[i][j]=0;
        }
    }
 
    if (solveNQUtil(board, 0,n) == false) {
        cout<<"No solution"<<endl;
        return false;
    }
 
    printSolution(board,n);
    return true;
}
int main()
{
    int n;
    cin>>n;
    solveNQ(n);
    return 0;
}