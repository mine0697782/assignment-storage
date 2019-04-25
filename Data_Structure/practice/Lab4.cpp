#include<iostream>
#include<string.h>
using namespace std;

const int stack_size = 2, queue_size = 3;

class Stack{
    private:
        char stack[stack_size];
        int top, i;
    public:
        Stack(){top = -1;}
        int isEmpty(){return top == -1;}
        int isFull(){return top == stack_size - 1;}
        void push(char input){
            if (!isFull())
                stack[++top] = input;
            else cout << "Stack is Full!" << endl;
        }
        char pop(){
            if (!isEmpty()) {
                cout << stack[top] << endl;
                return stack[top--];
            }
            else cout << "Stack is Empty!" << endl;
        }
        void displayStack(){
            if (!isEmpty()) {
                i = 0;
                cout << "Stack : ";
                while(i <= top)
                    cout << stack[i++] << " ";
                cout << endl;
            }
            else cout << "Stack is Empty!" << endl;
        }
};

class Queue{
    private:
        char queue[queue_size];
        int front, rear, count;
    public:
        Queue(){front = -1; rear = -1; count = 0;}
        int isEmpty(){return front == rear;}
        int isFull(){return front == queue_size - 1;}
        //int C_isFull(){return (front + 1) % queue_size == rear;}
        void enque(char input){
            if (!isFull())
                queue[++front] = input;
            else cout << "Queue is Full!" << endl;
        }
        void C_enque(char input){
            //if ((front + 1) % queue_size == rear)
            if (count == queue_size)
                cout << "C_Queue is Full!" << endl;
            else {
                front = (front + 1) % queue_size;
                queue[front] = input;
                count++;
            }
        }
        char deque(){
            if (!isEmpty()) {
                cout << queue[++rear] << endl;
                return queue[rear];
            }
            else cout << "Queue is Empty!" << endl;
        }
        char C_deque(){
            if (!isEmpty()) {
                rear = (rear + 1) % queue_size;
                cout << queue[rear] << endl;
                count--;
                return queue[rear];
            }
            else cout << "C_Queue is Empty!" << endl;
        }
        void displayQueue() {
            if (!isEmpty()) {
                int i = rear;
                cout << "Queue : ";
                while (i != front)
                    cout << queue[++i] << " ";
                cout << endl;
            }
            else cout << "Queue is Empty!" << endl;
        }
        void displayCqueue() {
            if (!isEmpty()) {
                int i = rear;
                cout << "Queue : ";
                while(i != front) {
                    cout << queue[++i] << " ";
                    i %= queue_size;
                }
                cout << endl;
            }
            else cout << "C_Queue is Empty!" << endl;
        }
};



main(){
    Stack s = Stack();
    Queue q = Queue();
    Queue cq = Queue();
    char input[20];
    char alpha;
    int num;

    cout << "Commands(push, pop, enque, deque, displayStack, displayQueue, C_enque, C_deque, displayCQ)" << endl;;
    while(1) {
        cout << "Command : ";
        cin >> input;

        if (strcmp(input, "push") == 0) {
            cin >> alpha;
            s.push(alpha);
        }
        else if (strcmp(input, "pop") == 0) {
            s.pop();
        }
        else if (strcmp(input, "enque") == 0) {
            cin >> alpha;
            q.enque(alpha);
        }
        else if (strcmp(input, "deque") == 0) {
            q.deque();
        }
        else if (strcmp(input, "displayStack") == 0) {
            s.displayStack();
        }
        else if (strcmp(input, "displayQueue") == 0) {
            q.displayQueue();
        }
        else if (strcmp(input, "C_enque") == 0) {
            cin >> alpha;
            cq.C_enque(alpha);
        }
        else if (strcmp(input, "C_deque") == 0) {
            cq.C_deque();
        }
        else if (strcmp(input, "displayCQ") == 0) {
            cq.displayCqueue();
        }
        else cout << "Bad Command!" << endl;
    }
}
