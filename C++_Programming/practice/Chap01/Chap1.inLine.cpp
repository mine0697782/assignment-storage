#include<iostream>
using namespace std;

template <typename T>

inline T SQUARE(T x){
    return x*x;
}

main(){
    //int num;
    double num;

    cout << "Input a Numver : ";
    cin >> num;

    cout << SQUARE(num) << endl;
    return 0;
}
