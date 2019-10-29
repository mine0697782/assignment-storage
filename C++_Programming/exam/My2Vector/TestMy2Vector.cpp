#include<iostream>
#include "My2Vector.h"
using namespace std;

void main(){
    int numTestCases;
    cin >> numTestCases;

    for (int i=0; i<numtestCases; i++){
        int coordX, coordY;

        cin >> coordX >> coordY;
        My2Vector v1(coordX, coordY);

        cin >> coordX >> coordY;
        My2Vector v2(coordX, coordY);
    
        cout << v1 << " " << v2 << endl;
        cout << 2*v1 + 3*v2 << endl;
    }

    return 0;
}
