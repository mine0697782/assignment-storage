#include<iostream>
#include<string.h>

using namespace std;

main(){
    char input[20];
    cin >> input;
    
    if (strcmp(input,"test") == 0)
        cout << "yeah" << endl;
    else cout << "No" << endl;
    
    return 0;
}
