#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> part(vector<int> arr, int data[], int s, int e, int ind, int m){
    vector<vector<int>> ans;
    if(ind==m){
        vector<int> res;
        for(int j=0; j<m; j++)
            res.push_back(data[j]);
        ans.push_back(res);
        return ans;
    }

    for(int i=s; i<=e && e-i+1>=m-ind;i++){
        data[ind] = arr[i];
        part(arr, data, i+1, e, ind+1, m);
    }
}

void f(vector<int> arr, int m){
    vector<vector<int>> ans;
    int data[m];
    ans = part(arr, data, 0, arr.size()-1, 0, m);
    for(auto i=ans.begin(); i!=ans.end(); i++){
        cout<<ans[i];
        cout<<endl;
    }
}

int main(){
    vector<int> a={1,2,3,4,5};
    f(a, 3);
    return 0;
}