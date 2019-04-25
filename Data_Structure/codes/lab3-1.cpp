#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>

using namespace std;

bool match(int a, int b) {if (a==b) return true; else return false;}

int check(char* str) {
    char exp[100] = *str;
    char stack[100] = -1;
    char temp;

    int stack_index = 0;
    

    for (int i=0; i<strlen(exp); i++){
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[') stack[stack_index++]=exp[i];
        if(exp[i]==')' || exp[i]=='}' || exp[i]==']') {
            if(stack_index<0)  cout << "UnBalanced" << endl; 
            else { 
                temp=stack[stack_index--];
                if(!match(temp, exp[i])) 
                    cout << "Mismatched" << temp << "and" << exp[i];
            }
        }
    }
    if(stack_index<0) return true; else {cout << "Unbalanced"; return false;}
}

main(){
    ifstream in;
    char buffer[100];
    bool validity;
    in.open("lab3.txt");
    while(in.getline(buffer,100)) {
        validity = check(buffer);
        if(validity) cout << "valid"; else cout << "Invalid" << endl;
    }

}
