#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x){
        this->data = x;
        this->left = NULL;
        this->right = NULL;
    }
};


void printTree(TreeNode* root){
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* node = q.front();
        q.pop();
        cout<<node->data<<" ";
        if(node->left)
            q.push(node->left);
        if(node->right)
            q.push(node->right);
    }
}

void inverse(TreeNode* root){
    if(root==NULL)
        return;
    TreeNode* tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    inverse(root->left);
    inverse(root->right);
}

int main(){
    TreeNode *node = new TreeNode(4);
    node->left = new TreeNode(2);
    node->right = new TreeNode(5);
    node->left->left = new TreeNode(3);
    node->left->right = new TreeNode(1);
    inverse(node);
    printTree(node);
    return 0;
}