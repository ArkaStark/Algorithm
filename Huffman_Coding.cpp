#include<bits/stdc++.h>
#include<iostream>
using namespace std;

struct MinHeapNode{
    char data;
    int f;
    MinHeapNode *l, *r;

    MinHeapNode(char data, int f){
        l = r = NULL;
        this->data = data;
        this->f = f;
    }
};

struct compare{
    bool operator()(MinHeapNode *l, MinHeapNode *r){
        return l->f > r->f;
    }
};

void printCodes(struct MinHeapNode *root, string s){
    if(!root)
        return;
    if(root->data != '$')
        cout<<root->data<<"\t"<<s<<endl;

    printCodes(root->l, s+"0");
    printCodes(root->r, s+"1");
}

string huff_coding(string msg){
    string code="";
    unordered_map<char, int> alph;
    int n = msg.length();
    for(int i=0; i<n; i++)
        alph[msg[i]]++;

    struct MinHeapNode *left, *right, *top;
    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;

    for(auto i=alph.begin(); i!=alph.end(); i++){
        cout<<i->first<<"\t"<<i->second<<endl;
        minHeap.push(new MinHeapNode(i->first, i->second));
    }
    cout<<"\n\n";
    while(minHeap.size() != 1){
        left = minHeap.top();
        minHeap.pop();
        right = minHeap.top();
        minHeap.pop();

        top = new MinHeapNode('$', left->f+right->f);
        top->l = left;
        top->r = right;
        minHeap.push(top);
    }

    printCodes(minHeap.top(), "");
    return code;
}

int main(){
    string msg = "bccabbddaeccbbaedccd";
    huff_coding(msg);
    //cout<<"\n\n Code is : "<<huff_coding(msg);
    return 0;    
}