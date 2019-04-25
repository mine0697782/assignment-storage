#include<iostream>
#include"temp.h"

using namespace std;

main(){
    cout << "Program start" << endl;

    cout << "1 + 2 : " << add(1, 2) << endl;
    cout << "4 - 3 : " << dif(4, 3) << endl;
    cout << "5 * 6 : " << mul(5, 6) << endl;
    cout << "6 / 3 : " << div(6, 3) << endl;


    cout << "Program End" << endl;
    return 0;
}
