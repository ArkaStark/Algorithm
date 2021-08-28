#include <iostream>
using namespace std;

class StackNode {
    public:
        char data;
        StackNode* next;
};

int isEmpty(StackNode* root){
    return !root;
}

StackNode* newNode(char brac){
    StackNode* stackNode = new StackNode();
    stackNode->data = brac;
    stackNode->next = NULL;
    return stackNode;
}

void push(StackNode** root, char brac){
    StackNode* stackNode = newNode(brac);
    stackNode->next = *root;
    *root = stackNode;
}

char peek(StackNode* root){
    if(isEmpty(root))
        return '-';
    return root->data;
}

void pop(StackNode** root){
    StackNode* temp = *root;
    *root = (*root)->next;
    free(temp);
}

void printStack(StackNode* root){
    while(!isEmpty(root)){
        cout<<root->data;
        root = root->next;
    }
}

int checker(string str){
    StackNode* root=NULL;
    for(int i=0;i<str.length();i++)
    {
        if(str[i]=='(' || str[i]=='{' || str[i]=='[')
            push(&root, str[i]);
        if(str[i]==')'){
            if(peek(root)!='(')
                return 0;
            else
                pop(&root);
        }
        if(str[i]=='}'){
            if(peek(root)!='{')
                return 0;
            else
                pop(&root);
        }
        if(str[i]==']'){
            if(peek(root)!='[')
                return 0;
            else
                pop(&root);
        }
        printStack(root);
    }
    return isEmpty(root);
}

int main() {
	//code
	int T;
	string str[100];
	cin>>T;
	for(int i=0;i<T;i++)
	{
	    cin>>str[i];
	    if(checker(str[i]))
	    cout<<"balanced\n";
	    else
	    cout<<"not balanced\n";
	}
	return 0;
}