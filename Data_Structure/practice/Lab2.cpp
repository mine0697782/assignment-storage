#include<iostream>
using namespace std;

int square[5][5] = {0};

void magicSquare(int n){
    //int square[n][n] = {0};
    int i, j, key, row, col;

    i = 0; j = n/2; key = 2;
    square[i][j] = 1;

    while (key <= n*n){
        if (i-1 < 0) row = n-1; 
        else row = i-1;
        if (j-1 < 0) col = n-1; 
        else col = j-1;

        if (square[row][col] != 0) i = (i+1) % n;
        else {i = row; j = col;}            
        square[i][j] = key++;
    }
    //return square;
}

main(){
    int n;
    //int **square;
    cout << "Enter N : ";
    cin >> n;

    if (n%2 != 1) {
        cout << "N has to be ODD number" << endl;
        return 0;
    }

    //square = magicSquare(n);
    magicSquare(n);
    for (int i = 0; i < n; i++){
//        square[i];
        for (int j = 0; j < n; j++)
            cout << square[i][j] << "\t";
        cout << endl;
    }
    return 0;
}
