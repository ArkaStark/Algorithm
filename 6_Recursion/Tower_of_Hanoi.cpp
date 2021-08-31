#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int toh(int n, char from, char to, char aux){
    
    static int res=0;
    
    if(n<=0)
        return 0;

    toh(n-1, from, aux, to);
    cout<<"Disc "<<n<<" : "<<from<<" -> "<<to;
    cout<<endl;
    res++;
    toh(n-1, aux, to, from);
    return res;
}

int main(){
    int n = 5;
    char f='A', t='C', aux='B';
    int res = toh(n, f, t, aux);
    cout<<"\n\nCount = "<<res;
    return 0;
}