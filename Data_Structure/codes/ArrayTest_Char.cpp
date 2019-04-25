#include<iostream>
#include<fstream>
#include<stdlib.h>

using namespace std;

void Test(char *s);

char *converter(char *buffer);

const int stackSize = 20;

class Stack {
    private:
        char stack[stackSize]; int top;
    public:
        Stack() {top = -1;}

        void push(char val) {stack[++top] = val;}
        char pop() {return stack[top--];}
        char showTop() {return stack[top];} // Temp func
        int isEmpty() {return top == -1;}
        int isFull() {return top == stackSize-1;}
        void displayStack() {
            int i;
            if (isEmpty()) cout << "Stack is empty!" << endl;
            else {
                i = 0;
                while(i <= top)
                    cout << stack[i++] << " ";
                cout << endl;
            }
        }
};

main(){
    char input[100];//, output[100];
    char *output;
    int i;

    cout << "Program Start" << endl;
    ifstream in;
    in.open("Hw2_example.txt");
    //in.open("arrayTest.txt");
    while(in.getline(input,100)) {
        cout << "========Input : " << input << endl;
        //Test(input);
        output = converter(input);
        cout << "--------Output : " << output << endl;
        i = 0;
        while (output[i] != '\0'){
            cout << output[i++] << " ";
        }
        cout << endl;
        
    }
    
    cout << "Program End" << endl;
    return 0;
}

char *converter(char *buffer){
    int i = 0;
    int index = 0;
    char token;

    char *result = new char[100];
    Stack op = Stack();
    
    cout << "function start" << endl; // temp

    while (buffer[i] != '\0') {
        token = buffer[i];

        if (isdigit(buffer[i])){
            result[index++] = buffer[i++]; //
        }
        else if (buffer[i] == '('){
            op.push(buffer[i++]);
        }
        else if (buffer[i] == ')'){
            while(op.showTop() != '('){
                result[index++] = op.pop(); //
            }
            i++;
            op.pop();
        }
        else if (buffer[i] == ' '){
            i++;
            continue;
        }
        else if (buffer[i] == '$'){
            break;
        }
        
        else if (token == '+') {
            if (op.isEmpty() || op.showTop() == '('){
                op.push(buffer[i++]);
            }
            else {
                result[index++] = op.pop(); //
                op.push(buffer[i++]);
            }
        }
        
        else if ((token == '+' || token == '-' ) || (token == '*' || token == '/')) {
            if (op.isEmpty() || op.showTop() == '('){
                op.push(buffer[i++]);
            }
            else {
                result[index++] = op.pop(); //
                op.push(buffer[i++]);
            }
        }

        cout << "operator stack : ";
        op.displayStack();
    }
    while (!op.isEmpty()){
        result[index++] = op.pop();
    }

    return result;
    
}




/*
void Test(char *s){
    int i = 0;
    
    while(s[i] != '\0'){
        cout << "s[" << i << "] : " << s[i] << "  to Int : " << int(s[i]) << endl;
        if (s[i] == '(')
            cout << "There is an '('" << endl;
        i++;
    }
    cout << "End of File" << endl;

}
*/
