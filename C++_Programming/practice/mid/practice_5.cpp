#include<iostream>

using namespace std;

main(){
    int n1, n2, n3;
    int large;

    cout << "Enter three integer : ";
    cin >> n1 >> n2 >> n3;

    if (n1 >= n2 && n1 >= n3)
        large = n1;
    else if (n2 >= n1 && n2 >= n3)
        large = n2;
    else if (n3 >= n1 && n3 >= n2)
        large = n3;
    cout << "The largest is " << large << endl;
}
