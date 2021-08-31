#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void heapify(int A[], int i, int n){
    if(i>n-1)
        return;
    int large = i;
    int l = 2*i+1;
    int r = 2*i+2;

    if(l<n && A[large] < A[l])
        large = l;
    if(r<n && A[large] < A[r])
        large = r;

    if(large!=i){
        swap(A[large], A[i]);
        heapify(A, large, n);
    }
}

int heap(int A[], int n, int k){
    for(int i=n/2-1; i>=0; i--)
        heapify(A, i, n);
    
    for(int i=n-1; i>=0; i--){
        swap(A[i], A[0]);
        heapify(A, 0, i);
    }
    return A[k-1];
}

int main(){
    int A[] = {3, 5, 7, 6, 9, 1};
    cout<<heap(A, 6, 4);
    return 0;
}