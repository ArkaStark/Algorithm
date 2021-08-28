#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int maxSumPairWithDiffLessThanK(int arr[], int N, int K){

}

int main(){
    int T;
    cin>>T;
    while(T--){
        int N; 
        cin>>N;
        int* arr = (int*)malloc(N*sizeof(int));
        for(int i=0; i<N; i++)
            cin>>arr[i];
    int K;
    cin>>K;
    cout<<maxSumPairWithDiffLessThanK(arr, N, K)<<endl;
    }
    return 0;
}

