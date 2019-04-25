#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

class Stack {
    private:
        char stack[50];
        int top;
    public:
        Stack(){top = -1;}
        int isEmpty(){return top == -1;}
        void push(char input){stack[++top] = input;}
        char pop(){
            if (!isEmpty()){
                return stack[top--];
            }
        }
        void print(){
            int i = 0;
            cout << "now stack : ";
            while (i <= top){
                cout << stack[i++] << " ";
            }
            cout << endl;
        }
};

int check(char *input){
    Stack s = Stack();
    int len = strlen(input);
    char token;

    if (len%2){
        for (int i = 0; i < len/2; i++){
            s.push(input[i]);
        }
        //s.print();
        for (int i = (len/2)+1; i < len; i++){
            if (s.isEmpty()){
                //cout << "empty" << endl;
                return 0;
            }
            token = s.pop();
            //cout << "token : " << token << " , ";
            if (input[i] != token){
                return 0;
            }
        }
        return 1;
    }
    else {
        for (int i = 0; i < len/2; i++){
            s.push(input[i]);
        }
        //s.print();
        for (int i = len/2; i < len; i++){
            if (s.isEmpty()){
                //cout << "empty" << endl;
                return 0;
            }
            token = s.pop();
            //cout << "token : " << token << " , ";
            if (input[i] != token){
                return 0;
            }
        }
        return 1;

    }
}

main(){
    char input[100];
    ifstream in;
    char *filename = "Lab3_data2.txt";
    in.open(filename);
    int result;

    for(int i = 0; i < 4; i++){
        in >> input;
        cout << input << "\t\t";
        result = check(input);
        if (result) {
            cout << "A Palindrome" << endl;
        }
        else {
            cout << "Not a Palindrome" << endl;
        }
    }
    return 0;
}
