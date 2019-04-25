#include<iostream>
using namespace std;

int reverseNumber(int n);

main() {
    int t, n;
    cin >> t;
    for (int i=0; i<t; i++) {/*
        total = 0;
        high = 0;
        cin >> n;
        for (j=0; j<n; j++){
            cin >> vote[j];
            total += vote[j];
        }
        half = (total / 2) + 1;
        for (j=0; j<n; j++){
            if (vote[j] >= half){
                high = j+1;
                break;
            }
        }
        cout << high << endl;
    */
    cin >> n;
    cout << reverseNumber(n) << endl;
    }
    return 0;
}

int reverseNumber(int n){
    int total = 0;
    int high = 0;
    int half = 0;
    int vote[100];
    for (int i=0; i<n; i++){
        cin >> vote[i];
        total += vote[i];
    }
    half = (total / 2) + 1;
    for (int i=0; i<n; i++){
        if (vote[i] >= half){
            high = i+1;
            break;
        }
    }
    return high;
}
