#include <iostream>
using namespace std;

class StackNode{
    public:
    int data;
    StackNode* next;
};

int isEmpty(StackNode* root){
    return !root;
}

StackNode* newNode(int data){
    StackNode* stackNode = new StackNode();
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}

void push(StackNode** root, int data){
    StackNode* stackNode = newNode(data);
    stackNode->next = (*root);
    *root = stackNode;
}

int peek(StackNode* root){
    return root->data;
}

void pop(StackNode** root){
    StackNode* temp = *root;
    *root = (*root)->next;
    free(temp);
}


int main() {
	//code
	int T;
	cin>>T;
	StackNode* root = NULL;
    int Arr[100][10000];
	for(int i=0;i<T;i++){
	    int N;
	    cin>>N;
	    for(int j=0; j<N; j++)
	        cin>>Arr[i][j];
	    push(&root, Arr[i][0]);
        for(int j=1; j<N; j++){
            while (peek(root)<Arr[i][j]){
                pop(&root);
                cout<<Arr[i][j]<<" ";
            }
            push(&root, Arr[i][j]);
        }
        while(isEmpty(root) == 0){
            pop(&root);
            cout<<"-1 ";
        }
	    cout<<"\n";
	}
	return 0;
}