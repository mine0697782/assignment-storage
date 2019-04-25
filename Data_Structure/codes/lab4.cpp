#include <iostream>
#include<string> 
#include<stdlib.h>
using namespace std;

const int stackSize = 3;
int stack[stackSize];
int top;
int main(){
    void create_stack(), push(int), traverse_stack(); displayStack();
    int pop(); int isFull(), isEmpty();
    int num; char input[10];
    
    create_stack();
    
    while (1) {
        cout<<"Enter command(push, pop, traverse, exit):";
        cin >> input;
        
        if (strcmp(input, "push") == 0) {
            if (!isFull()) {
                cout << "Enter an integer to push => ";
                cin >> num;
                push(num);
            }
            else
            cout << "Stack is full!\n";
        }
        else if (strcmp(input, "pop") == 0) {
            if (!isEmpty()) {
            num = pop();
            cout << num << " is popped.\n";
            }
            else
            cout << "Stack is em pty!\n";
        }
        else if (strcmp(input, "traverse") == 0) displayStack();
        else if (strcmp(input, "exit") == 0) exit(0);
        else cout << "Bad Command!\n";
    }
}
void create_stack() {
    top = -1; 
}

int isFull() {
    if (top == stackSize - 1) return 1;
    else return 0; 
}
    
int isEmpty() {
    if (top == -1) return 1;
    else return 0; 
}

void push(int num) {
    ++top;
    stack[top] = num;
}

int pop() {
    return (stack[top--]);
}

void displayStack() {
    int sp;
    if (isEmpty()) cout << "Stack is empty!" << endl;
    else {
        sp = top;
        while (sp != -1) {
            cout << stack[sp]; 
            --sp;
        }
        cout << endl;
    }
}
