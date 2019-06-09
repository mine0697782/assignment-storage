#include<iostream>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    cout << "now a, b, temp : " << a << " " << b << " " << temp << endl;
    
    a = b;
    b = temp;
    return;
}

main(){
    int num1, num2;
    cin >> num1 >> num2;
    cout << "Your input : " << num1 << ", " << num2 << endl;

    swap(num1,num2);
    cout << "Swap : " << num1 << ", " << num2 << endl;

    return 0;
}
