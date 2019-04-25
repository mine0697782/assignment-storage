#include<iostream>
#include<string.h>
using namespace std;

main(){
    char s1[20] = "Sex Master";

    cout << "Fisrt " << strchr(s1,'M') << endl;
    cout << "d" << endl;
    cout << strchr(s1,'e') << endl;

    cout << "Third " << strstr(s1,"ex") << endl;
    
    /*
    char c1 = 'A';
    char c2 = '6';

    cout << "c1 : " << c1 << " c2 : " << c2 << endl;

    if (isalpha(c1))
        cout << "c1 is alpha" << endl;
    if (isupper(c1))
        cout << "c1 is upper" << endl;
    if (islower(c1))
        cout << "c1 is lower" << endl;
    if (isdigit(c1))
        cout << "c1 is digit" << endl;
    if (isalpha(c2))
        cout << "c2 is alpha" << endl;
    if (isupper(c2))
        cout << "c2 is upper" << endl;
    if (islower(c2))
        cout << "c2 is lower" << endl;
    if (isdigit(c2))
        cout << "c2 is digit" << endl;
    */
    return 0;
}
