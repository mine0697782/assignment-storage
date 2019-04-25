#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

class Stack{
    private:
        char stack[20];
        int top;
    public:
        Stack(){top = -1;}
        int isEmpty(){return top == -1;}
        void push(char input){stack[++top] = input;}
        char pop(){
            //cout << "pop : " << stack[top-1] << endl;;
                return stack[top--];
        }
};

int match(char a, char b){
    //cout << "match :: a = " << a << " / b = " << b << endl;
    if (a == '(' && b == ')')
        return 1;
    else if (a == '{' && b == '}')
        return 1;
    else if (a == '[' && b == ']')
        return 1;
    else 
        return 0;
}

int check(char *input) {
    Stack s = Stack();
    char token;

    for (int i = 0; i < strlen(input); i++){
        if (input[i] == '(' || input[i] == '{' || input[i] == '[') 
            s.push(input[i]);
        if (input[i] == ')' || input[i] == '}' || input[i] == ']') {
            if (s.isEmpty()){
                cout << "1 ";
                return 2;
            }
            else {
                token = s.pop();
                //cout << "token : " << token << " ";
                if (!match(token,input[i])){
                    cout << "2 ";
                    return 3;
                }
            }
        }
    }
    if (s.isEmpty()){
        cout << "3 ";
        return 1;
    }
    else{ 
        cout << "4 ";
        return 2;
    }
}

main(){
    Stack s = Stack();
    char input[100];
    int result;
    ifstream in;
    char *filename = "Lab3_data1.txt";
    in.open(filename);
    
    while(in.getline(input,100)){
        result = check(input);
        if (result == 1)  // Valid
            cout << "Valid" << endl;
        else if (result == 2)  // Unbalance
            cout << "Invalid (Unbalanced)" << endl;
        else if (result == 3) // Mismatch
            cout << "Invalid (Mismatched)" << endl;
    }
}
