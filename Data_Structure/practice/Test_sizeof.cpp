#include<iostream>
#include<string.h>
//#include<stdlib.h>
using namespace std;

main(){
    char s[20];
    char *s2;
    //cout << "first : " << sizeof(s) << endl;
    //cin >> s;
    s2 = "string123";
    cout << "s2 : " << s2 << " / size : " << sizeof(s2) << " / len : " << strlen(s2) << endl;
    //cout << "second : " << s << " = " << sizeof(s) << endl;
    //cout << "third : " << s << " = " << strlen(s) << endl;
    return 0;
}
