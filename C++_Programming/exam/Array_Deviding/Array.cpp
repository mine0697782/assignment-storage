#include<iostream>
#include<fstream>

using namespace std;

const int SIZE = 10;
void rotateArray(int array[], int size);
void printArray(int array[], int size);

int main(){
    int t;
    unsigned int size;
    int array[SIZE];

    //ifstream in;
    //in.open("input.txt");
    cin >> t; //

    for (int i=0; i<t; i++){
        cin >> size; //
        for (int j=0; j<size; j++){
            cin >> array[j]; //
        }
        rotateArray(array, size);
        printArray(array, size);
    }

    return 0;
}

void rotateArray(int array[], int size)
{
    int temp[SIZE];
    //temp = array;
    int index = 0;
    for (int mod = 1; mod >= 0; mod--){
        for (int i=0; i<size; i++){
            if (array[i]%2 == mod){
                temp[index++] = array[i];
            }
        }
    }

    for (int i=0; i<size; i++){
        array[i] = temp[i];
    }
}

void printArray(int array[], int size)
{
    for (int i=0; i<size; i++){
        cout << array[i] << " ";
    }
    cout << endl;
}
