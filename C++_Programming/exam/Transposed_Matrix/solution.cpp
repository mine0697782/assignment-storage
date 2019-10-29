#include<iostream>
#include<fstream>

using namespace std;

const int SIZE = 10;
void transposeSquareMatrix(int matrix[][SIZE], int size);
void printSquareMatrix(int matrix[][SIZE], int size);

int main(){
    int t;
    unsigned int size;
    int squareMatrix[SIZE][SIZE];
    

    //ifstream in;
    //in.open("input.txt");
    cin >> t;   //

    for (int i=0; i<t; i++){
        cin >> size; //
        for (int j=0; j<size; j++){
            for (int k=0; k<size; k++){
                cin >> squareMatrix[j][k]; //
            }
        }
        transposeSquareMatrix(squareMatrix, size);
        printSquareMatrix(squareMatrix, size);
    }

    return 0;
}

void transposeSquareMatrix(int matrix[][SIZE], int size){
    int temp;
    for (int r=1; r<size; r++){
        for (int c=0; c<r; c++){
            temp = matrix[r][c];
            matrix[r][c] = matrix[c][r];
            matrix[c][r] = temp;
        }
    }
}

void printSquareMatrix(int matrix[][SIZE], int size){
    for (int i=0; i<size; i++){
        for (int j=0; j<size; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
