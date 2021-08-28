#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void f(int u, int N, vector<char> S, vector<vector<int>> E, string &s){
    for(int i=0; i<N-1; i++){
        if(E[i][0] == u){
            f(E[i][1], N, S, E, s);
        }
    }
    s = s+S[u-1];
}

int main(){
    vector<vector<int>> E;
    int N;
    cin>>N;
    for(int i=0; i<N-1; i++){
        int x, y;
        cin>>x>>y;
        vector<int> tmp;
        tmp.push_back(x);
        tmp.push_back(y);
        E.push_back(tmp);
    }
    vector<char> S;
    for(int i=0; i<N; i++){
        char c;
        cin>>c;
        S.push_back(c);
    }
    string s = "";
    f(2, N, S, E, s);
    cout<<s<<endl;
    return 0;
}