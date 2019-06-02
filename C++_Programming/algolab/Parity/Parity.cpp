#include<iostream>
#include<fstream>

using namespace std;

main(){
    ifstream in;
    in.open("input.txt");

    int n, num, t, count;

    in >> t;
    
    while(t--){
        count = 0;
        in >> n;
        num = n;
        while(num >= 1) {
            count += num % 2;
            num /= 2;
        }

        if (count%2 == 0){
            cout << n << endl;
        }
        else {
            cout << n + 2147483648 << endl;
        }
    }
}
