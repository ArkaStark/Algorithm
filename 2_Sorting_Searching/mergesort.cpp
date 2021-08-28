#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void merge(int **A, int l, int mid, int h){
    int **A1 = new int*[mid-l+1];
    int **A2 = new int*[h-mid+1];
    for(int i=0; i<mid-l+1; i++)
        A1[i] = new int[2];
    for(int i=0; i<h-mid+1; i++)
        A2[i] = new int[2];
    for(int i=0; i<mid-l; i++){
        A1[i][0] = A[l+i][0];
        A1[i][1] = A[l+i][1];
    }
    A1[mid-l][0] = INT_MAX;
    for(int j=0; j<h-mid; j++){
        A2[j][0] = A[mid+j][0];
        A2[j][1] = A[mid+j][1];
    }
    A2[h-mid][0] = INT_MAX;

    int i=0, j=0;
    for(int k=l; k<h; k++){
        if(A1[i][0]<=A2[j][0]){
            A[k][0] = A1[i][0];
            A[k][1] = A1[i][1];
            i++;
        }
        else{
            A[k][0] = A2[j][0];
            A[k][1] = A2[j][1];
            j++;
        }
    }
    delete(A1);
    delete(A2);
}

void printA(int **A, int l, int h){
    for(int i=l; i<h; i++)
        cout<<A[i][0]<<" "<<A[i][1]<<endl;
}

void mergesort(int **A, int l, int h){
    if(l<h-1){
        int mid = (l+h)/2;
        mergesort(A, l, mid);
//        printA(A, l, mid);
//        cout<<"***"<<endl;
        mergesort(A, mid, h);
//        printA(A, mid, h);
//        cout<<"....."<<endl;
        merge(A, l, mid, h);
//        printA(A, l, h);
//        cout<<"############"<<endl;
    }
}

int main(){
    int n;
    cin>>n;
    int **A = new int*[n];
    for(int i=0; i<n; i++){
        A[i] = new int[2];
        cin>>A[i][0]>>A[i][1];
    }
    mergesort(A, 0, n);
    cout<<"\n#####################"<<endl;
    printA(A, 0, n);
    return 0;
}