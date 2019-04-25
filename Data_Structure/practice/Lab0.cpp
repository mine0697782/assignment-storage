#include<iostream>
#include<fstream>
using namespace std;

int counter(char *line){
    int IN = 1, OUT = 0;
    int state = OUT;
    int count = 0;
    int i = 0;

    while(line[i] != '\0'){
        if (state == OUT){
            if (isalpha(line[i])){
                state = IN;
                count++;
            }
        }
        else {
            if (line[i] == ' ')
                state = OUT;
        }
        i++;
    }
    return count;
}

main(){
    char filename[50] = "lab0_text.txt";
    char line[200];
    int num, total = 0;

    ifstream in;
    in.open(filename);

    while(in.getline(line,200)){
        cout << line << endl;
        num = counter(line);
        total += num;
        cout << "The number of words : " << num << endl;
    }
    cout << "total number : " << total << endl;

    return 0;
}
