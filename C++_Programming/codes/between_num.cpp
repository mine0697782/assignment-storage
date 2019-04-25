#include<iostream>
using namespace std;

main(){
    int t, a, b, m;
    cin >> t;
    for (int i=0; i<t; i++){
        cin >> a >> b >> m;
        cout << ((a<=m && m<=b)?1:0) << endl;
    }
    return 0;
}
