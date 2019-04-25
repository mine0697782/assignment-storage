#include<iostream>
using namespace std;

int angleClock(int h, int m);

main(){
    int t;
    int h, m;
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> h >> m;
        cout << angleClock(h, m) << endl;
    }

    return 0;    
}

int angleClock(int h, int m){
    double angle;
    double higher, lower;
    double hour = (h*30) + (m*0.5);
    double minute = m*6;
    double dif;
    dif = hour - minute;
    if (dif < 0) dif *= -1;
    if (dif > 180) angle = 360 - dif;
    else angle = dif;

    /*
    if (hour>minute) {higher = hour; lower = minute;}
    else if (hour<minute) {higher = minute; lower = hour;}
    else return 0;
    
    dif = higher - lower;
    if (dif < 180) {angle = dif;}
    else if (dif > 180) {360 - dif;}
    else return 180;
    */
    return angle;
}
