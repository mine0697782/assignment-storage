#include<iostream>
#include<fstream>
#include<algorithm>
#include<cmath>
using namespace std;

main(){
    ifstream in;
    in.open("input.txt");
    int x1, x2, x3, y1, y2, y3, t;
    int arr[3];
    in >> t;

    for (int i=0; i<t; i++){
        in >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        
        arr[0] = abs(x1-x2);
        arr[1] = abs(x2-x3);
        arr[2] = (;
        
        
        sort(arr,arr+3);
        

        if (

    }
}
