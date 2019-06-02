#include<iostream>
#include<fstream>

using namespace std;

struct P{
    int x, y;  
};

main(){
    int t, area, sign;
    ifstream in;
    in.open("input.txt");
    P p[3];
    
    in >> t;

    for (int i=0; i<t; i++){
        for (int i=0; i<3; i++){
            in >>p[i].x >> p[i].y;
        }
        for (int i=1; i<=2; i++){
            p[i].x -= p[0].x;
            p[i].y -= p[0].y;
        }
        area = (p[1].x * p[2].y - p[1].y * p[2].x);
        sign = (area > 0) ? 1 : ((area == 0) ? 0 : -1);
        cout << area*sign << " " << sign << endl;
    }
}
