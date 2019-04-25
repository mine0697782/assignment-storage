#include<iostream>
using namespace std;

void swap(int *a, int *b);
/*
void swap(char c1, char c2);

void swap(double n1, double n2);
*/
main(){
    int num1 = 10, num2 = 20;
    cout << "num1 : " << num1 << " num2 : " << num2 << endl;
    swap(&num1, &num2);
    cout << "num1 : " << num1 << " num2 : " << num2 << endl;
/*
    char c1 = 'A', c2 = 'Z';
    cout << "Char1 : " << c1 << " Char2 : " << c2 << endl;
    swap(&c1, &c2);
    cout << "Char1 : " << c1 << " Char2 : " << c2 << endl;

    double n1 = 1.11, n2 = 3.14;
    cout << "Double1 : " << n1 << " Double2 : " << n2 << endl;
    swap(&n1, &n2);
    cout << "Double1 : " << n1 << " Double2 : " << n2 << endl;
*/
    return 0;
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}


