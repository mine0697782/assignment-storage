#include<iostream>
using namespace std;

#define SQUARE(X) (X*X)

main(){
    //Sex
    int num;
    cout << "input a Number : ";
    cin >> num;

    cout << SQUARE(num) << endl;
    return 0;
}
