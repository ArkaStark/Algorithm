#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void quicksort(int A[], int l, int h){
    if(l<h){
        int i=l, j=h;
        while(i<j){
            while(A[i]<=A[l])
                i++;
            while(A[j]>A[l])
                j--;
            if(i<j)
                swap(A[i], A[j]);
        }
        swap(A[l], A[j]);
        quicksort(A, l,j);
        quicksort(A, j+1,h);
    }
}

int main(){
    int n;
    cin>>n;
    int A[n+1];
    for(int i=0; i<n; i++)
        cin>>A[i];
    A[n] = INT_MAX;
    quicksort(A, 0, n);
    for(int i=0; i<n; i++)
        cout<<A[i]<<" ";
    cout<<endl;
    return 0;
}
