#include<iostream>
#include"header_01_04.h"

using namespace std;
/*
namespace Sex{
    void gogo();
    void sex();
}

namespace Kiss{
    void gogo();
}
*/
main(){
    Sex::gogo();
    Kiss::gogo();
    return 0;
}
/*
void Sex::gogo(){
    cout << "Sex Go Go!" << endl;
    sex();
    Kiss::gogo();
}

void Sex::sex(){
    cout << "Yeah, Sex!!!" << endl;
}

void Kiss::gogo(){
    cout << "Kiss Go Go!" << endl;
}*/
