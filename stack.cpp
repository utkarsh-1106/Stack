// Stack using Array

#include<bits/stdc++.h>
using namespace std;
struct Stack{
	int size;
	int numOfElement;
	int top;
	int *stackList;
};
bool isEmpty(struct Stack *s){
	return (s->top == -1) ? 1 : 0;
}
bool isFull(struct Stack *s){
	return (s->top == s->size-1) ? 1 : 0;
}
void push(struct Stack *s, int value){
	cout<<endl;
	if(isFull(s)){
		cout<<"Stack is Full\n";
		return;
	} else {
		s->top++;
		s->stackList[s->top] = value;
		s->numOfElement++;
	}
}
int peek(struct Stack *s, int pos = 1){
	cout<<endl;
	if(isEmpty(s)){
		cout<<"Stack is Empty\n";
		return INT_MAX;
	} else if(pos>0 && pos<=s->numOfElement){
		return s->stackList[s->top-pos+1];
	} else {
		cout<<"Invalid position\n";
		return INT_MIN;
	}
}
int pop(struct Stack *s){
	cout<<endl;
	if(isEmpty(s)){
		cout<<"Stack is Empty\n";
		return INT_MIN;
	} else {
		int x = s->stackList[s->top];
		s->top--;
		s->numOfElement--;
		return x;
	}
}
void display(struct Stack s){
	cout<<endl;
	cout<<"Displaying Stack:\n";
	cout<<"Top\n";
	for(int i=s.top; i>=0; i--){
		cout<<"----\n";
		cout<<"|"<<s.stackList[i]<<"|"<<endl;
	}cout<<"----\n";
}
int main(){
    int choice, flag = 1, pos;
	struct Stack newStack;
	cout<<"Enter maximum size of stack: ";
	cin>>newStack.size;
	newStack.numOfElement = 0;
	newStack.top = -1;
	newStack.stackList = new int[newStack.size];
	cout<<"1. For pushing element in stack press '1'\n";
	cout<<"2. For poping out element in stack press '2'\n";
	cout<<"3. For peeking an element in the stack press '3'\n";
	cout<<"4. For displaying stack element press '4'\n";
	cout<<"5. For displaying number of element present in the stack press '5'\n";
	while(flag != 0){
	    cout<<"\nEnter choice '1', '2', '3', '4' or '5': ";
    	cin>>choice;
    	switch(choice){
    	    case 1:
	    	    cout<<"\nEnter value to push: ";
	    	    int value;
	    	    cin>>value;
	    	    push(&newStack, value);
	    	    break;
    	    case 2:
	    	    cout<<"\nPopped item: "<<pop(&newStack);
	    	    break;
    	    case 3:
	    	    cout<<"\nEnter the position of item you want to peek: ";
	    	    cin>>pos;
	    	    cout<<"\nThe "<<pos<<"th element is: "<<peek(&newStack, pos);
	    	    break;
    	    case 4:
	    	    display(newStack);
	    	    break;
    	    case 5:
	    	    cout<<"\nNumber of element present in the stack is: "<<newStack.numOfElement;
	    	    break;
    	    default:
	    	    cout<<"\nEnter valid choice\n";
	    	    break;
	    }
	    cout<<"\nWant to continue press '1' else press '0': ";
	    cin>>flag;
	}
	return 0;
}

// Stack using Linked-List

#include<bits/stdc++.h>
using namespace std;
struct stackNode{
	int data;
	struct stackNode *next;
}*Top = NULL;
int numOfElement = 0;
bool isEmpty(){
	return (Top == NULL) ? 1 : 0;
}
bool isFull(){
	struct stackNode *newNode = new stackNode;
	int full = (newNode == NULL) ? 1 : 0;
	return full;
}
void push(int value){
	cout<<endl;
	struct stackNode *newNode = new stackNode;
	if(newNode == NULL){
		cout<<"\nStack is Full";
	} else {
		newNode->data = value;
		newNode->next = Top;
		Top = newNode;
		numOfElement++;
	}
}
int pop(){
	cout<<endl;
	if(isEmpty()){
		cout<<"\nStack is Empty";
		return INT_MIN;
	} else {
		struct stackNode *temp = Top;
		int value = Top->data;
		Top = Top->next;
		numOfElement--;
		delete temp;
		return value;
	}
}
int peek(int pos){
	cout<<endl;
	if(isEmpty()){
		cout<<"\nStack is Empty";
		return INT_MIN;
	} else if(pos>0 && pos<=numOfElement){
		struct stackNode *p = Top;
		while(--pos){
			p = p->next;
		}
		return p->data;
	} else {
		cout<<"Invalid position\n";
		return INT_MIN;
	}
}
void display(){
	cout<<endl;
	struct stackNode *temp = Top;
	cout<<"Displaying Stack:\n";
	cout<<"Top\n";
	while(temp){
		cout<<"----\n";
		cout<<"|"<<temp->data<<"|"<<endl;
		temp = temp->next;
	}cout<<"----\n";
}
int main(){
	int choice, flag = 1, pos;
	cout<<"1. For pushing element in stack press '1'\n";
	cout<<"2. For poping out element in stack press '2'\n";
	cout<<"3. For peeking the stack press '3'\n";
	cout<<"4. For displaying stack element press '4'\n";
	cout<<"5. For displaying number of element present in the stack press '5'\n";
	while(flag != 0){
	    cout<<"\nEnter choice '1', '2', '3', '4' or '5': ";
    	cin>>choice;
    	switch(choice){
    	    case 1:
	    	    cout<<"\nEnter value to push: ";
	    	    int value;
	    	    cin>>value;
	    	    push(value);
	    	    break;
    	    case 2:
	    	    cout<<"\nPopped item: "<<pop();
	    	    break;
    	    case 3:
	    	    cout<<"\nEnter the position of item you want to peek: ";
	    	    cin>>pos;
	    	    cout<<"\nThe "<<pos<<"th element is: "<<peek(pos);
	    	    break;
    	    case 4:
	    	    display();
	    	    break;
    	    case 5:
	    	    cout<<"\nNumber of element present in the stack is: "<<numOfElement;
	    	    break;
    	    default:
	    	    cout<<"\nEnter valid choice\n";
	    	    break;
	    }
	    cout<<"\nWant to continue press '1' else press '0': ";
	    cin>>flag;
	}
	return 0;
}
