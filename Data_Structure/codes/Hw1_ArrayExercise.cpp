/************************************************************
* Name : 정민재
* Student ID : 20181688
* Program ID : HomeWork #1
* Description : N*M 크기의 행렬의 행과 열을 각각 Transpose 하는것
* Algorithm : 개선된 희소 행렬 전치
* Functions : "fast_transpose" - a와 b 행렬이 주어졌을때 a의 행과 열을 뒤집어서 b에 넣는 것
*
*************************************************************/

#include<iostream>
#include<string>
#include<fstream>
using namespace std;

struct term{ int row, col, value;};



/***********************************************************
* Function : (fast) Transpose
* Description : 희소행렬에서 값이 없는 구간을 제외해서 복잡도를 최소화하는 것
* Variables
*       -row_term : 정렬되지 않은 열들의 각 갯수를 저장하는 변수
*       -starting_pos : 정렬되지 않은 열들을 순서대로 옮기기 위해 지정하는 인덱스
*       -i, j : 배열 인덱스
*       -num_cols : 열의 갯수
*       -num_terms : 값의 갯수
*
***********************************************************/
void fast_transpose(term a[], term b[]){
    int MAX_COL = 100;
    int row_terms[MAX_COL], starting_pos[MAX_COL];
    int i, j, num_cols = a[0].col, num_terms = a[0].value;

    b[0].row = num_cols;
    b[0].col = a[0].row;
    b[0].value = num_terms;

    if(num_terms > 0) {
        for(i=0; i<num_cols; i++)
            row_terms[i] = 0;
        for(i=1; i<=num_terms; i++)
            row_terms[a[i].col]++;

        starting_pos[0] = 1;
        for(i=1; i<num_cols; i++)
            starting_pos[i] = starting_pos[i-1] + row_terms[i-1];

        for(i=1; i<=num_terms; i++) {
            j = starting_pos[a[i].col]++;
            b[j].row = a[i].col;
            b[j].col = a[i].row;
            b[j].value = a[i].value;
        }
    }
}

main(){
    
    ifstream in;
    in.open("lab2-1.txt");
    
    term term_a[9];
    term term_b[9];
    
    for(int i=0; i<9; i++){
        in >> term_a[i].row
           >> term_a[i].col
           >> term_a[i].value;
    } 

    in.close();

    fast_transpose(term_a, term_b);
    
    cout << "term A : \n================" << endl;
    for(int i=0; i<9; i++)
        cout << term_a[i].row << " " << term_a[i].col << " " << term_a[i].value << endl;
    
    
    cout << "\n\nterm B : \n================" << endl;
    for(int i=0; i<9; i++)
        cout << term_b[i].row << " " << term_b[i].col << " " << term_b[i].value << endl;
    
}
