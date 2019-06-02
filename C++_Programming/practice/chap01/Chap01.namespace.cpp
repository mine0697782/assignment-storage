#include<iostream>

using namespace std;

namespace Sex {
    
    void print();// {cout << "Ang~" << endl;}

}

namespace Kiss {

    void print();// {cout << "Umm~" << endl;}

}

main() {
    
    Sex::print();
    Kiss::print();
}

void Sex::print() {cout << "Ang~" << endl;}
void Kiss::print() {cout << "Umm~" << endl; Sex::print();}
