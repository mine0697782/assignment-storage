#include<iostream>
using namespace std;

main(){
    int *arr, *temp;
    temp = arr;
    for (int i = 0; i < 10; i++){
        *arr = i;
        cout << *arr << " ";
        arr++;
    }
    cout << endl;
    for (int i = 0; i < 10; i++)
        cout << *--arr<< endl;
    return 0;
}
