#include <iostream>
#include<cmath>

using namespace std;

int closestNumber(int n, int m);

main(){
    int t;
    int n, m;
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> n >> m;
        cout << closestNumber( n, m ) << endl;
    }
    return 0;
}

int closestNumber(int n, int m){
    double div = n / m;
    double result;
    //(div*2 < n) 
    result = ceil(div)*m;
    //else result = (div+1)*m;
    return result;
}
