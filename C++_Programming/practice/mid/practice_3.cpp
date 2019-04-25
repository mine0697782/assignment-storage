#include<iostream>
#include<cmath>

using namespace std;

main(){
    double x1, x2, y1, y2;
    double dis;
    
    cout << "Enter First dot (x1, y1) : ";
    cin >> x1 >> y1;
    cout << "Enter Second dot (x2, y2) : ";
    cin >> x2 >> y2;

    dis = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));

    cout << "Distance = " << dis << endl;
}
