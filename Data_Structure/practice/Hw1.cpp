#include<iostream>
#include<fstream>
using namespace std;

struct matrix {
    int row, col, value;
};

void transpose(matrix a[], matrix b[]){
    int MAX_COL = 100;
    int row_terms[MAX_COL], starting_pos[MAX_COL];
    int i, j, num_col = a[0].col, num_value = a[0].value;

    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].value = a[0].value;

    if (num_value > 0){
        for (i=0; i<num_col; i++)
            row_terms[i] = 0;
        for (i=1; i<=num_value; i++)
            row_terms[a[i].col]++;
        
        starting_pos[0] = 1;
        for(i=1; i<num_col; i++){
            starting_pos[i] = starting_pos[i-1] + row_terms[i-1];
        }
        for(i=1; i<=num_value; i++){
            j = starting_pos[a[i].col]++;
            b[j].row = a[i].col;
            b[j].col = a[i].row;
            b[j].value = a[i].value;
        }

    }

}

main(){
    int row, col, value;
    ifstream in;
    in.open("Hw1_data.txt");

    cout << "start" << endl; //
    
    in >> row >> col >> value;

    cout << "1" << endl; //

    matrix a[value+1];
    matrix b[value+1];

    cout << "2" << endl; //

    a[0].row = row;
    a[0].col = col;
    a[0].value = value;
    for(int i=1; i<=value; i++){
        in >> a[i].row >> a[i].col >> a[i].value;
    }
    
    cout << "3" << endl; //

    transpose(a, b);

    cout << "result ==== " << endl;
    for (int i=0; i<9; i++){
        cout << b[i].row << " " << b[i].col << " " << b[i].value << endl;
    }
    return 0;
}
