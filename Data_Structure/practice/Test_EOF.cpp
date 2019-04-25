#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

main(){
    char input[100];
    char word[20];
    int i;
    ifstream in;
    in.open("Lab3_data2.txt");
   
    while(in.getline(input,100)){
        i = 0;
        while(input[i] != '\0'){
            
        }
        cout << "input : " << input << endl;
    
        if (input == '\0')
            cout << "1" << endl;
        else
            cout << "2" << endl;
    }
    return 0;
}
