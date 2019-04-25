#include<iostream>
using namespace std;

main(){
    int t, n, two, five;
    unsigned long num;
    cin >> t;
    for (int i = 0; i < t; i++){
        cin >> n;
        two = 0;
        five = 0;
        for (int j = 0; j < n; j++){
            cin >> num;
            while (!(num%2)){
                two++;
                num /= 2;
            }
            while (!(num%5)){
                five++;
                num /= 5;
            }
        }
        cout << min(two,five) << endl;
    }

    return 0;
}
