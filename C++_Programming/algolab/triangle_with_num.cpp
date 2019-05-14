#include<iostream>
using namespace std;

void makePass(int *&array, int k);

main(){
    int k;

    cin >> k;
    int *pass;
    makePass(pass, k);
    
    for (int i = 0; i < k; i++){
        cout << pass[i] << " ";
        delete[] pass;
    }
    cout << endl;
    //delete[] pass;
    for (int i = 0; i < k; i++){
        cout << pass[i] << " ";
    }
}

void makePass(int *&array, int k){
    array = new int[k];
    int sum;

    array[0] = 0;
    sum = 0;
    for (int i = 1; i < k; i++){
        cout << "now i : " << i << endl;
        array[i] = array[i-1] + (k-i+1);
        cout << "array[" << i << "] : " << array[i] << endl;
    }
}
