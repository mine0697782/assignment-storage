#include<iostream>
#include<fstream>
using namespace std;

void Test(char *s);

main(){
    char input[100];
    char filename[50] = "text.txt";
    
    ifstream in;
    in.open(filename);
    while(in.getline(input,100))
        Test(input);
    return 0;
}

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
