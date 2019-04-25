#include<iostream>
using namespace std;

main() {
    int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int total;
    int n, year, mon, day;
    int i, j;
    cin >> n;
    for (i = 0; i < n; i++) {
        total = 0;
        cin >> year >> mon >> day;
        total += day;
        for (j = 0; j < mon-1; j++)
            total += months[j];
        if (((year%4 == 0 && year%100 != 0) || year%400 == 0) && mon>2) 
            total++;
        cout << total << endl;
    }
    return 0;
}
