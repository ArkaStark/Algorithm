#include <iostream>                 // working till move_i = 63 for some sequence of x_move, y_move
#include<bits/stdc++.h>
#define N 8
#define x0 0
#define y0 0
using namespace std;

int KTourUtil(int x, int y, int move_i, int sol[N][N], int x_move[N], int y_move[N]);

void printSol(int sol[N][N]){
    cout<<"\n\n";
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++)
            cout<<" "<<setw(2)<<sol[i][j]<<" ";
    cout<<endl;
    }
}

int isValid(int x, int y, int sol[N][N]){
    return (x>=0 && x<N && y>=0 && y<N && sol[x][y]==-1);
}

void KTour(){
    int sol[N][N];
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            sol[i][j] = -1;

    int x_move[N] = {2, 1, -1, -2, -2, -1, 1, 2};
    int y_move[N] = {1, 2, 2, 1, -1, -2, -2, -1}; 

    sol[x0][y0] = 0;

    if(KTourUtil(x0, y0, 1, sol, x_move, y_move))
        printSol(sol);
    else
    {
        cout<<"NO SOLUTION!";
    }
    
}

int KTourUtil(int x, int y, int move_i, int sol[N][N], int x_move[N], int y_move[N]){
    int x_next, y_next;
    if(move_i == 64)
        return 1;
    //cout<<move_i<<" ";
    for(int k=0; k<8; k++)
    {
        x_next = x + x_move[k];
        y_next = y + y_move[k];
        if(isValid(x_next, y_next, sol)){
            sol[x_next][y_next] = move_i;
            if(KTourUtil(x_next, y_next, move_i+1, sol, x_move, y_move))
                return 1;
            else
                //BackTracking
                sol[x_next][y_next] = -1; 
        }
    }
    return 0;
}


int main(){
    KTour();
    return 0;
}