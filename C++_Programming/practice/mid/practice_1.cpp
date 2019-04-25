#include<iostream>
using namespace std;

main(){
    int num[3];
    for (int i = 0; i < 3; i++) {
        cout << "Enter Integer : ";
        cin >> num[i];
    }
    cout << "Average is : " << (num[0] + num[1] + num[2])/3 << ". " << endl;
    return 0;
}
