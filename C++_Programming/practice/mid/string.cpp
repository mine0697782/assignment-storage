#include<iostream>
#include<string.h>

using namespace std;

main(){
    char str1[10] = "sex!";
    char str2[10] = "Sibal!";
    char str3[10];
    strcpy(str3,str1);

    cout << "before========" << endl;
    cout << str1 << endl << str2 << endl;
    strcpy(str1, str2);

    cout << "cpy After========" << endl;
    cout << str1 << endl << str2 << endl;

    strcat(str2,str3);
    cout << "cat After========" << endl;
    cout << str2 << endl << str3 << endl;

    return 0;
}
