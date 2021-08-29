
// C++ program for recursive level
// order traversal in spiral form
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
 
// A binary tree node has data,
// pointer to left child and a
// pointer to right child
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        this->data = x;
        this->left = NULL;
        this->right = NULL;
    }
};


void sfs(vector<int> &ans, Node* root, bool ltr, int lvl){
    if(!root)
        return;
    if(lvl == 1)
        ans.push_back(root->data);
    else if(lvl > 1){
        if(ltr){
            sfs(ans, root->left, ltr, lvl-1);
            sfs(ans, root->right, ltr, lvl-1);
        }
        else{
            sfs(ans, root->right, ltr, lvl-1);
            sfs(ans, root->left, ltr, lvl-1);
        }
    }
}

int level(Node *root){
    if(root==NULL)
        return 0;
    return max(level(root->left), level(root->right))+1;
}

//Function to return a list containing the level order traversal in spiral form.
vector<int> findSpiral(Node *root)
{
    //Your code here
    vector<int> ans;
    int h = level(root);
    bool ltr = false;
    for(int i=1; i<=h; i++){
        sfs(ans, root, ltr, i);
        ltr = !ltr;
    }
    return ans;
}

int main()
{
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(7);
    root->left->right = new Node(6);
    root->right->left = new Node(5);
    root->right->right = new Node(4);

    vector<int> ans = findSpiral(root);
    for(auto i=ans.begin(); i!=ans.end(); i++)
        cout<<*i<<" ";
    return 0;
}