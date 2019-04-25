#include<iostream>
using namespace std;

main(){
    int a, b, c, d, t, i, n;
    cin >> t;
    for (i=0; i<t; i++){
        cin >> a >> b >> c >> d;
        if (b < c || d < a)
            n = -1;
        else
            n = min(b,d) - max(a,c);
        cout << n << endl;
    }
}
