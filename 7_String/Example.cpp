#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void print_freq(string s){
    int n = s.length();
    int mp[256];
    for(int i=0; i<256; i++){
        mp[i] = 0;
    }
    for(int i=0; i<n; i++){
        mp[int(s[i])]++;
    }

    for(int i=0; i<256; i++){
        if(mp[i]>0){
            cout<<char(i)<<" "<<mp[i];
            cout<<endl;
        }
    }

}

int main(){
    string s = "ARKA";
    print_freq(s);
    return 0;
}