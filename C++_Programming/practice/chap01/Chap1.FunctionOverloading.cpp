#include<iostream>
using namespace std;

void MyFunc(void){
    cout << "Normal Sex" << endl;
    return;
}

void MyFunc(char c){
    cout << "Char Sex " << c << endl;
    return;
}

void MyFunc(int i){
    cout << "Int Sex " << i << endl;
    return;
}

void MyFunc(int i, int j){
    cout << "Twin Sex " << i << " With " << j << endl;
    return;
}

main(){
    MyFunc();
    MyFunc('s');
    MyFunc(3);
    MyFunc(6, 9);
    return 0;

}
