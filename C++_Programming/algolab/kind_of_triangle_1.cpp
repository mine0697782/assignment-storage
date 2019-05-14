#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

main(){
    ifstream in;
    in.open("input.txt");
    int a, b, c, t;
    int arr[3];
    in >> t;

    int big;
    for (int i=0; i<t; i++){
        in >> a >> b >> c;
        
        arr[0] = a;
        arr[1] = b;
        arr[2] = c;
        sort(arr,arr+3);
        
        if (a+b <= c || b+c <= a || a+c <= b){
            cout << 0 << endl;
        }

        else if (a == b && b == c){
            cout << 1 << endl;
            continue;
        }
            
                else if (arr[2]*arr[2] == (arr[1]*arr[1])+(arr[0]*arr[0])){
            cout << 2 << endl;
            continue;
        }
        else if (a == b || b == c || a == c){
            cout << 3 << endl;
            continue;
        }
        else {
            cout << 4 << endl;
        }


    }
}
