// { Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

Node* merge(Node* head1, Node* head2) {
    Node* result = NULL;
    if(head1 == NULL)
        return head2;
    else if(head2 == NULL)
        return head1;
    if(head1->data < head2->data)
    {
        result = head1;
        result->next = merge(head1->next, head2);
    }
    else
    {
        result = head2;
        result->next = merge(head1, head2->next);
    }
    return result;
}   

Node* split(Node* source, Node** front, Node** back)
{
    Node* slow = source, *fast = source->next;
    while(fast)
    {
        fast = fast->next;
        if(fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *front = source;
    *back = slow->next;
    slow->next = NULL;
    //printList(*front);
    //printList(*back);
}

Node* mergeSort(Node** head) {
    // your code here
    Node* source = *head;
    Node *a, *b;
    if(source == NULL || source->next == NULL )
    {
        return source;
    }
    split(source, &a, &b);
    mergeSort(&a);
    mergeSort(&b);
    *head = merge(a,b);
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

/* Driver program to test above functions*/
int main() 
{ 
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        mergeSort(&a);
        printList(a);
    }
    return 0;
} 