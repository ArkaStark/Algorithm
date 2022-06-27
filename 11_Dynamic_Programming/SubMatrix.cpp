#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int print_submatrix(vector<vector<int>> &A, int x, int y, int m, int n){
    int s=0;
    for(int i=x; i<m; i++){
        for(int j=y; j<n; j++){
                cout<<A[i][j]<<"\t";
                s+=A[i][j];
            }
            cout<<endl<<endl;
        }
        cout<<"**************************"<<endl;
        return s;
}

void print_allSM(vector<vector<int>> &A, int x, int y, int m, int n, int &mx){
    if(x>=m || y>=n || m<0 || n<0)
        return;
    int s = print_submatrix(A, x, y, m, n);
    mx = max(s, mx);
    print_allSM(A, x+1, y, m, n, mx);
    print_allSM(A, x, y+1, m, n, mx);
    print_allSM(A, x, y, m-1, n, mx);
    print_allSM(A, x, y, m, n-1, mx);


}

int main(){
    vector<vector<int>> A = {{1, -1, 2}, {0, 1, -2}, {2, 0, -3}, {1, 5, 2}};
    int m = A.size();
    int n = A[0].size();
    int mx = INT_MIN;
    print_allSM(A, 0, 0, m, n, mx);
    cout<<mx;
    return 0;
}