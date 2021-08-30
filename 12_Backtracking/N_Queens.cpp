#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isSafe(int **B, int r, int c, int N){
    int i, j;
    for(i=0; i<c; i++){
        if(B[r][i])
            return false;
    }
    for(i=r, j=c; i>=0 && j>=0; i--, j--){
        if(B[i][j])
            return false;
    }
    for(i=r, j=c; i<N && j>=0; i++, j--){
        if(B[i][j])
            return false;
    }
    return true;
}

bool nQ(int **B, int col, int N){
    if(col >= N)
        return true;
    for(int i=0; i<N; i++){
        if(isSafe(B, i, col, N)){
            B[i][col] = 1;
            if(nQ(B, col+1, N))
                return true;
            B[i][col] = 0;
        }
    }
    return false;
}


int main(){
    int n;
    cin>>n;

    for(int k=0; k<n; k++){
        int **board = new int*[n];
        for(int i=0; i<n; i++)
            board[i] = new int[n];
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                board[i][j] = 0;
        board[k][0] = 1;
        if(nQ(board, 1, n)){
            cout<<"*****************"<<endl;
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++)
                    cout<<board[i][j]<<" ";
                cout<<endl;
            }
    
        }
    }
    return 0;
}