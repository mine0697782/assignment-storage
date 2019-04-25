#include<iostream>
using namespace std;

#define PYEONG 3.3

main(){
    int num;
    cout << "Enter area via (m**2) : ";
    cin >> num;
    cout << "It's " << num/PYEONG << " pyeong." << endl;
    return 0;
}
