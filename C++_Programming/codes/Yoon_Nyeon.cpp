#include<iostream>
using namespace std;

main() {
    int i, t, year;
    cin >> t;
    for (i = 0; i < t; i++) {
        cin >> year;
        cout << int((year%4 == 0 && year%100 != 0) || year%400 == 0) << endl;;
    }
    return 0;
}
