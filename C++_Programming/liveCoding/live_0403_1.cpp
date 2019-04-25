#include<iostream>
using namespace std;

int reverseNumber(int n);

main() {
    int i, j, t, num, pass, len, n[20];
    cin >> t;
    for(i=0; i<t; i++) {
        cin >> num;
        /*
        j = 0;
        len = 0;
        while(num) {
            n[j++] = num%10;
            num /= 10;
            len++;
        }
        pass = 0;
        for (int k=0; k<len; k++){
            if (n[k] != 0)
                pass = 1;
            if (pass == 1)
                cout << n[k];
        }
        cout << endl;*/
        reverseNumber(num);
    }
}

int reverseNumber(int num){
    int i, j, len, pass, n[20];
    int output[20];
    j = 0;
    len = 0;
    while(num) {
        n[j++] = num%10;
        num /= 10;
        len++;
    }
    pass = 0;
    i = 0;
    for (int k=0; k<len; k++){
        if (n[k] != 0)
            pass = 1;
        if (pass == 1)
            output[i++] = n[k];
    }
    for (int k=0; k<len; k++)
        cout << output[k];
    cout << endl;
}
