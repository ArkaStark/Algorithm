#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void clone(stack<int> st, stack<int> &cloned){
    int size = 0;
    
    while(size != st.size() - 1)
    {
        int top = st.top();
        st.pop();
        
        while(size != st.size())
        {
            cloned.push(st.top());
            st.pop();
        }
        
        st.push(top);
        
        while(!cloned.empty())
        {
            st.push(cloned.top());
            cloned.pop();
        }
        
        size++;
    }
    
    while(!st.empty())
    {
        cloned.push(st.top());
        st.pop();
    }
}
