#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;

const int stackSize = 2;
const int queueSize = 3;

// PUSH, POP, StackFull, StackEmpty, DislayStack
// Enqueue, Deque, QueueFull, QueueEmpty, DisplayQ
// C-Enque, C-Deque, display-CQ


class Stack{
    private:
        char stack[stackSize]; int top;
    public:
        // Create Stack
        Stack() {top = -1;}
        
        void push(char val) {stack[++top] = val;}
        char pop() {return stack[top--];}
        int isEmpty() {return top == -1;}
        int isFull() {return top == stackSize -1;}
        
        //void stack_full() {cout << "Stack Is Full!" << endl;}
        //void stack_empty() {cout << "Stack Is Empty!" << endl;}
        void displayStack() {
            int sp;
            if (isEmpty()) cout << "Stack is empty!" << endl;
            else {
                sp = top;
                while (sp != -1) {
                    cout << stack[sp] << " "; --sp;
                }
                cout << endl;
            }
        }


        //void push(int top, int item)
};

class Queue{
    private:
        int queue[queueSize]; int front, rear;
        char Cqueue[queueSize];
        //const int sizeQueue;
    public:
        Queue() {front = -1; rear = -1;}

        void enqueue(int val) {
            if (rear == queueSize-1) {queue_full(); return;}
            queue[++rear] = val;
        }

        void C_enqueue(char val) {
            rear = (rear+1) % queueSize;
            if (front == rear) {cout << "Queue is full!\n";}
            else Cqueue[rear] = val;
        }
        
        int dequeue() {
            if (front == rear) cout << "Queue is empty!\n";
            else {
                front = (front+1) % queueSize;
                return queue[front];
            }
        }

        char C_dequeue() {
            if (front == rear) return queue_empty();
            return Cqueue[++front];
        }
        
        void print() {
            int i;
            if (queue_empty()) cout << "Queue is Empty!" << endl;
            else {
                i = front + 1;
                cout << "-- Print Queue --" << endl;
                while (i <= rear) {
                    cout << queue[i] << " ";
                    i += 1;
                }
                cout << endl;
            }
        }
        
        void C_print() {
            int i;
            if (queue_empty()) cout << "Queue is Empty!" << endl;
            else {
                cout << "C print" << endl; //asdasdsadsadsad
                i = front + 1;
                cout << "-- Print Queue --" << endl;
                while (i <= rear) {
                    cout << Cqueue[i] << " ";
                    i += 1;
                }
                cout << endl;
            }
        }

        int queue_full() {
            if (rear == queueSize-1) return true;
            else return false;
        }

        int queue_empty() {
            if (front == rear) return true;
            else return false;
        }
};


main(){
    char num; char alp; char input[20];
    
    Queue q = Queue();
    Queue cq = Queue();
    Stack s = Stack();

    while(1) {
        cout << "\nEnter command(push, pop, enqueue, dequeue, C_enqueue, C_dequeue, displayS, displayQ, displayCQ) : ";
        cin >> input;
        
        if (strcmp(input, "push") == 0) {
            if (!s.isFull()) {
                cout << "Enter an integer to push => ";
                cin >> num;
                s.push(num);
            } else cout << "Stack is full!\n";
        }

        else if (strcmp(input, "pop") == 0) {
            if(!s.isEmpty()) {
                num = s.pop();
                cout << num << " is popped.\n";
            }
            else cout << "Stack is empty!\n";
        }
        
        else if (strcmp(input, "enqueue") == 0) {
            if (!q.queue_full()) {
                cout << "Enter an integer to enqueue => ";
                cin >> num;
                q.enqueue(num);
            } else cout << "Queue is full!\n";
        }
        
        else if (strcmp(input, "dequeue") == 0) {
            if (!q.queue_empty()) {
                num = q.dequeue();
                cout << num << " is dequeued.\n";
            }
            else cout << "Queue is Empty!\n";
        }
        
        else if (strcmp(input, "C_enqueue") == 0) {
            if (!cq.queue_full()) {
                cout << "Enter an integer to enqueue => ";
                cin >> alp;
                cq.C_enqueue(alp);
            } else cout << "Queue is full!\n";
        }
        
        else if (strcmp(input, "C_dequeue") == 0) {
            if (!cq.queue_empty()) {
                alp = cq.C_dequeue();
                cout << alp << " is dequeued.\n";
            }
            else cout << "Queue is Empty!\n";
        }

        else if (strcmp(input, "displayS") == 0) {
            s.displayStack();
        }
        
        else if (strcmp(input, "displayQ") == 0) {
            if (!q.queue_empty()) q.print();
            else cout << "Queue is Empty!\n";
        }
        
        else if (strcmp(input, "displayCQ") == 0) {
            if (!cq.queue_empty()) cq.C_print();
            else cout << "Queue is Empty!\n";
        }
        
        else if (strcmp(input, "exit") == 0) exit(0);
        
        else cout << "Bad Command!\n";
    }
}


























