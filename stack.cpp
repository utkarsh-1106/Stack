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
