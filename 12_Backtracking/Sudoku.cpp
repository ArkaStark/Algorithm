#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<char>> &grid, int row,
                       int col, char num)
{
     
    // Check if we find the same num
    // in the similar row , we
    // return false
    for (int x = 0; x <= 8; x++)
        if (grid[row][x] == num)
            return false;
 
    // Check if we find the same num in
    // the similar column , we
    // return false
    for (int x = 0; x <= 8; x++)
        if (grid[x][col] == num)
            return false;
 
    // Check if we find the same num in
    // the particular 3*3 matrix,
    // we return false
    int startRow = row - row % 3,
            startCol = col - col % 3;
   
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i + startRow][j +
                            startCol] == num)
                return false;
 
    return true;
}
    bool sudoku(vector<vector<char>> &board, int r, int c){
        if(r==8 && c==9)
            return true;
        if(c==9){
            r++;
            c=0;
        }
        
        if(board[r][c]=='.'){
            for(char k='1'; k<='9'; k++){
                if(isSafe(board, r, c, k)){
                        board[r][c] = k;
                        if(sudoku(board, r, c+1))
                            return true;
                }
            }
            board[r][c] = '.';
        }
        else
            return sudoku(board, r, c+1);
        return false;
    }

int main(){
    vector<vector<char>> board;
    board = {{'5', '3', '.', '.', '7', '.', '.','.', '.'},
             {'6', '.', '.', '1', '9', '5', '.','.', '.'},
             {'.', '9', '8', '.', '.', '.', '.','6', '.'},
             {'8', '.', '.', '.', '6', '.', '.','.', '3'},
             {'4', '.', '.', '8', '.', '3', '.','.', '1'},
             {'7', '.', '.', '.', '2', '.', '.','.', '6'},
             {'.', '6', '.', '.', '.', '.', '2','8', '.'},
             {'.', '.', '.', '4', '1', '9', '.','.', '5'},
             {'.', '.', '.', '.', '8', '.', '.','7', '9'}};
    if(sudoku(board, 0, 0))
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++)
                cout<<" "<<board[i][j];
            cout<<endl;
        }
    else{
        cout<<"INPUT SUDOKU IS INVALID";
    }

    return 0;
}