#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int x){
        this->data = x;
        this->next = NULL;
    }
};

bool detectLoop(Node* head){
    Node* fast = head;
    Node* slow = head->next;
    while(fast != NULL && fast->next != NULL && slow != NULL){
        if(fast == slow)
            return true;
        fast = fast->next->next;
        slow = slow->next;
    }
    return false;
}

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    Node* loop = new Node(4);
    head->next->next->next = loop;
    loop->next = new Node(5);
    loop->next->next = NULL;
    cout<<detectLoop(head);
}