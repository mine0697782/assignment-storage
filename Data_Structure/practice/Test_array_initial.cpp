#include<iostream>
using namespace std;

main(){
    int square[5][5] = {0};
    
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++)
            cout << square[i][j] << " ";
        cout << endl;
    }
    return 0;
}
