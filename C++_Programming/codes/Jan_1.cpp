#include<iostream>
using namespace std;

main() {
    int total;
    int t, n;
    int i, j;
    cin >> t;
    for (i = 0; i < t; i++) {
        cin >> n;
        total = (n-1582)*365;
        for (int j=1582; j<n; j++){
            if ((j%4 == 0 && j%100 != 0) || j%400 == 0){
                total++;
                //cout << "total up" << endl;
            }
        }
        //cout << total << endl;
        cout << (total+5)%7 << endl;
//        cout << total << endl;
    }
    return 0;
}
